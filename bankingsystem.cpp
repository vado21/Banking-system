/*Tecnologico de Monterrey Campus Monterrey Materia:Programacion Orientada a Objetos Gpo:10
Autor del problema: Eduardo Andre Martínez Romero   Matricula: A00891264 Maestra: Martha Sordia Salinas
Fecha de entrega: 5 de Mayo 2017  */

/// This is a final project school coded in C++ which is a banking system using OOP and pointers
/// In this banking system you can make transactions and consult your current balance, it has Username and password access.
/// Every client could have one or more number account,which every one has currents balance.
/// Every client only has one client's number and one password.
#include <stdio.h>
#include <string>
#include <fstream>
#include "Fecha.h"
#include <iostream>
#include "Cliente.h"
#include "Ahorro.h"
#include "Cheques.h"
#include <math.h>
#include "Cuenta.h"
#include "Lista.h"
#include "Transacciones.h"
#include "Configuracion.h"
using namespace std;

/// This functions generates a file with the deposits, withdrawals and current balance from a client number for each number account

void generarestadosdecliente(Cliente *p,int iN,Configuracion c)
{
    for (int iCont = 0; iCont<iN;iCont++){
        Cuenta *cuentas[15];
        int iCantcuentas;
        p[iCont].GetCuentas(cuentas,iCantcuentas);
        string sId = "A00819264_";
        sId = sId + p[iCont].GetsId();
        sId = sId + "_";
        sId = sId + "cuentas.txt";
        ofstream texto(sId.c_str());
        texto<<"CLIENTE : "<<p[iCont].GetsNombre()<<endl;
        texto<<"TELEFONO : "<<p[iCont].GetsTelefono()<<endl;
        texto<<" EMAIL :"<<p[iCont].GetsEmail()<<endl;
        for(int iX = 0; iX<iCantcuentas;iX++){
            if(cuentas[iX]->GetcTipo()=='1'){
                double depositostotales = cuentas[iX]->sumatotaldepositos();
                double retirostotales = cuentas[iX]->sumatotalretiros();
                double dSaldoInicial = cuentas[iX]->GetSaldoinicial();
                double dSaldoGenerado = (cuentas[iX]->sumatotaldepositos()-cuentas[iX]->sumatotalretiros());
                double dSaldoInteres = dSaldoGenerado * (c.GetIntereses()/100);
                double dSaldototal = dSaldoInteres + dSaldoGenerado + dSaldoInicial;
                texto<<"                 BANCA TEC                   "<<endl;
                texto<<"              Cuenta de Ahorro                   "<<endl;
                texto<<"Numero de Cuenta :  "<<cuentas[iX]->GetCuenta()<<"         Saldo Anterior :  $"<<dSaldoInicial<<endl;
                texto<<"Nombre del Cliente :    "<<p[iCont].GetsNombre()<<"         Saldo Generado   : $"<<dSaldoGenerado<<endl;
                texto<<"                                                Intereses : ("<<c.GetIntereses()<<"%)  $"<<dSaldoInteres<<endl;
                texto<<"                                                Saldo Total : $"<<dSaldototal<<endl;
                texto<<"Fecha                Deposito               Retiro                Saldo"<<endl;
                cuentas[iX]->generarEstadoCuenta(texto);
                texto<<"                       "<<depositostotales<<"                  "<<retirostotales<<endl;
            }
            else if(cuentas[iX]->GetcTipo()=='2'){
                double depositostotales = cuentas[iX]->sumatotaldepositos();
                double retirostotales = cuentas[iX]->sumatotalretiros();
                double dSaldoInicial = cuentas[iX]->GetSaldoinicial();
                double dMovimientos = depositostotales-retirostotales;
                double dComsion = c.GetdComision();
                double dSaldoTotal = dSaldoInicial + dMovimientos - dComsion;
                texto<<"                 BANCA TEC                   "<<endl;
                texto<<"              Cuenta de Cheques                   "<<endl;
                texto<<"Numero de Cuenta :  "<<cuentas[iX]->GetCuenta()<<"         Saldo Anterior :  $"<<dSaldoInicial<<endl;
                texto<<"Nombre del Cliente :    "<<p[iCont].GetsNombre()<<"         Movimientos  : $"<<dMovimientos<<endl;
                texto<<"                                                       Comision : "<<dComsion<<endl;
                texto<<"                                                   Saldo Actual : "<<dSaldoTotal<<endl;
                texto<<"Fecha                Deposito              Retiro                 Saldo"<<endl;
                cuentas[iX]->generarEstadoCuenta(texto);
                texto<<"                       "<<depositostotales<<"                   "<<retirostotales<<endl;
            }
        }
    }
}
/// This functions generates a file with the deposits, withdrawals and current balance from a number account
void estadodecuenta(Cuenta *cuentas[],int icuentas,Cliente *p,int iX,Configuracion c)
{

    if(cuentas[icuentas]->GetcTipo()=='1'){
        string scliente;
        string sFechas;
        string scuenta = "Ahorro.txt";
        Fecha fecha;
        sFechas = fecha.estadofecha();
        scliente = "A00819264_";
        scliente += sFechas;
        scliente += scuenta;
        double depositostotales = cuentas[icuentas]->sumatotaldepositos();
        double retirostotales = cuentas[icuentas]->sumatotalretiros();
        double dSaldoInicial = cuentas[icuentas]->GetSaldoinicial();
        double dSaldoGenerado = (cuentas[icuentas]->sumatotaldepositos()-cuentas[icuentas]->sumatotalretiros());
        double dSaldoInteres = dSaldoGenerado * (c.GetIntereses()/100);
        double dSaldototal = dSaldoInteres + dSaldoGenerado + dSaldoInicial;
        ofstream texto(scliente.c_str());
        texto<<"                 BANCA TEC                   "<<endl;
        texto<<"              Cuenta de Ahorro                   "<<endl;
        texto<<"Numero de Cuenta :  "<<cuentas[icuentas]->GetCuenta()<<"         Saldo Anterior :  $"<<dSaldoInicial<<endl;
        texto<<"Nombre del Cliente :    "<<p[iX].GetsNombre()<<"         Saldo Generado   : $"<<dSaldoGenerado<<endl;
        texto<<"                                                Intereses : ("<<c.GetIntereses()<<"%)  $"<<dSaldoInteres<<endl;
        texto<<"                                                Saldo Total : $"<<dSaldototal<<endl;
        texto<<"Fecha                  Deposito              Retiro                Saldo"<<endl;
        cuentas[icuentas]->generarEstadoCuenta(texto);
        texto<<"                     "<<depositostotales<<"                      "<<retirostotales<<endl;
        }
    else if(cuentas[icuentas]->GetcTipo()=='2'){
        string scliente;
        string sFechas;
        string scuenta = "Cheques.txt";
        Fecha fecha;
        sFechas = fecha.estadofecha();
        scliente = "A00819264_";
        scliente += sFechas;
        scliente += scuenta;
        double depositostotales = cuentas[icuentas]->sumatotaldepositos();
        double retirostotales = cuentas[icuentas]->sumatotalretiros();
        double dSaldoInicial = cuentas[icuentas]->GetSaldoinicial();
        double dMovimientos = depositostotales-retirostotales;
        double dComsion = c.GetdComision();
        double dSaldoTotal = dSaldoInicial + dMovimientos - dComsion;
        ofstream texto(scliente.c_str());
        texto<<"                 BANCA TEC                   "<<endl;
        texto<<"              Cuenta de Cheques                   "<<endl;
        texto<<"Numero de Cuenta :  "<<cuentas[icuentas]->GetCuenta()<<"         Saldo Anterior :  $"<<dSaldoInicial<<endl;
        texto<<"Nombre del Cliente :    "<<p[iX].GetsNombre()<<"         Movimientos  : $"<<dMovimientos<<endl;
        texto<<"                                                       Comision : "<<dComsion<<endl;
        texto<<"                                                   Saldo Actual : "<<dSaldoTotal<<endl;
        texto<<"Fecha                Deposito              Retiro                 Saldo"<<endl;
        cuentas[icuentas]->generarEstadoCuenta(texto);
        texto<<"                       "<<depositostotales<<"                   "<<retirostotales<<endl;
    }
}

///This void function display all the transactions from a number account
void vertransacciones(Cuenta *cuentas[],int icuentas)
{
    cuentas[icuentas]->desplegarTransacciones();
}
///This void function display the current balance from a number account
void consultasaldo(Cuenta* cuentas[],int icuentas,Configuracion c)
{

    Fecha fecha;
    cuentas[icuentas]->saldo(fecha);
    if((cuentas[icuentas]->GetcTipo())=='1'){
        double dSaldoGenerado = (cuentas[icuentas]->sumatotaldepositos()-cuentas[icuentas]->sumatotalretiros())*(c.GetIntereses()/100);
        double dSaltotal = dSaldoGenerado + cuentas[icuentas]->GetdSaldototal();
        cout<<"INTERES = "<<dSaldoGenerado<<endl;
        cout<<"Saldo Total = "<<dSaltotal<<endl;
    }
    else if((cuentas[icuentas]->GetcTipo() == '2')){
        double dSaldoInicial = cuentas[icuentas]->GetSaldoinicial();
        double dMovimientos = (cuentas[icuentas]->sumatotaldepositos()-cuentas[icuentas]->sumatotalretiros());
        double dComsion = c.GetdComision();
        double dSaldoTotal = dSaldoInicial + dMovimientos - dComsion;
        cout<<"Comision : "<<dComsion<<endl;
        cout<<"Saldo Total = "<<dSaldoTotal<<endl;
    }
}
///This void function makes a withdrawal from a number account
void retiro(Cuenta* cuentas[],int icuentas,Configuracion c){

    double dMonto;
    cout<<"Cuanto retiraras en la cuenta"<<endl;
    cin>>dMonto;
    Fecha fecha;
    if((cuentas[icuentas]->GetcTipo())=='1'){
        double dSaldoDisponible;
        dSaldoDisponible = cuentas[icuentas]->GetdSaldototal() - c.GetiSaldoMinimo();
        if(dSaldoDisponible>=dMonto){
            cuentas[icuentas]->retiro(dMonto,fecha);
        }
        else{
            cout<<"NO PUEDE RETIRAR MAS DEL SALDO DISPONIBLE"<<endl;
        }
    }
    else if((cuentas[icuentas]->GetcTipo() == '2')){
        if((cuentas[icuentas]->GetdSaldototal()- dMonto)>=0){
            cuentas[icuentas]->retiro(dMonto,fecha);
        }
        else{
            cout<<"TU CUENTA NO SE PUEDE QUEDAR CON MENOS DE  0 "<<endl;
        }
    }
}
///This void function makes a deposit from a number account
void deposito(Cuenta* cuentas[],int icuentas){

    double dMonto;
    Fecha fecha;
    cout<<"Cuanto depositaras en la cuenta"<<endl;
    cin>>dMonto;
    cuentas[icuentas]->deposito(dMonto,fecha);
}
///This function reads a file of the restrictions that has the Banking system
Configuracion leerconfiguracion(){
    double dIntereses;
    double dComision;
    int iSaldoMinimo;
    int iTiempoBloqueo;
    Configuracion conf;
    ifstream  configurar("Configuracion.txt");
    while(configurar.eof() == false){
        configurar>>dIntereses;
        configurar>>dComision;
        configurar>>iSaldoMinimo;
        configurar>>iTiempoBloqueo;
    }
    conf = Configuracion(dIntereses,dComision,iSaldoMinimo,iTiempoBloqueo);
    return conf;
}
/// This bool function verifies if it is correct the username and the password
bool validarusuariocompleto(Cliente *p,int iN,string sUsuario,string sContrasenia,int &iX){

    for(int iCont = 0;iCont<iN;iCont++){
        if(p[iCont].GetsId() == sUsuario && p[iCont].GetsContrasenia() == sContrasenia ){
            iX = iCont;
            return true;
        }
    }
    return false;
}
/// This bool function verifies if it is correct form a username the password
bool validarcontrasenia(Cliente *p,int iN,string sContrasenia,int iX){

        if(p[iX].GetsContrasenia() == sContrasenia ){
            return true;
        }
    return false;
}
/// This bool function verifies if exists the username
bool validarusuario(Cliente *p,int iN,string sUsuario,int &iX){

    for(int iCont = 0; iCont<iN;iCont++){
        if(p[iCont].GetsId() == sUsuario ){
            iX = iCont;
            return true;
        }
    }
    return false;
}

bool validarcuenta(Cliente *p,string sNumerodeCuenta,int iId,int &iNumCuenta,Cuenta *cuentas[],int &iX){

    int iNumerodeCuentas;
    p[iId].GetCuentas(cuentas,iNumerodeCuentas);
    iX = iNumerodeCuentas;
    for(int iCont = 0;iCont<iNumerodeCuentas;iCont++){
            string sComp;
            sComp = cuentas[iCont]->GetCuenta();
        if(sComp == sNumerodeCuenta){
            iNumCuenta = iCont;
            return true;
        }
    }
    return false;
}

bool validarcliente(Cliente *p,int iN,string sId,int &iId){

    for(int iCont =0;iCont<iN;iCont++){
        if(p[iCont].GetsId() == sId ){
            iId=iCont;
            return true;
        }
    }
    return false;
}
///This  function reads from a file all the existing transactions from the clients
Cliente* leertransacciones(Cliente *p,int iN)
{
    ifstream depositos("Transacciones.txt");
    string sId;
    string sNumerodeCuenta;
    char cTipo;
    int iDia;
    int iMes;
    int iAnio;
    int iHora;
    int iMin;
    int iSeg;
    double dMonto;
    int iId;
    int iNumCuenta;
    Fecha fecha;
    int iX;
    while(depositos.eof() == false){
        Cuenta *cuentas[15];
        depositos>>sId;
        depositos>>sNumerodeCuenta;
        depositos>>cTipo;
        depositos>>iDia;
        depositos>>iMes;
        depositos>>iAnio;
        depositos>>iHora;
        depositos>>iMin;
        depositos>>iSeg;
        depositos>>dMonto;
        fecha = Fecha(iDia,iMes,iAnio,iHora,iMin,iSeg);
        if(validarcliente(p,iN,sId,iId) == true){
            if(validarcuenta(p,sNumerodeCuenta,iId,iNumCuenta,cuentas,iX) == true){
                if(cTipo == 'd'){
                    cuentas[iNumCuenta]->deposito(dMonto,fecha);
                    p[iId].SetCuentas(cuentas,iX);
                }
                else if(cTipo == 'r'){
                    cuentas[iNumCuenta]->retiro(dMonto,fecha);
                    p[iId].SetCuentas(cuentas,iX);
                }
                else if(cTipo == 's'){
                    cuentas[iNumCuenta]->saldo(fecha);
                    p[iId].SetCuentas(cuentas,iX);
                }

            }
        }
    }
    return p;
}

///This  function reads from a file all the number account from the clients
Cliente* leercuentas(Cliente *p,int iN,Configuracion c)
{
    string sId;
    char cTipo;
    string sNumerodeCuenta;
    double dSaldoInicial;
    int iId;
    ifstream cuentas("Cuentas.txt");
        while (cuentas.eof() == false){
            cuentas>>sId;
            cuentas>>cTipo;
            cuentas>>sNumerodeCuenta;
            cuentas>>dSaldoInicial;
            if(validarcliente(p,iN,sId,iId)== true){
                int iS;
                if(cTipo == '1'){
                p[iId].agregarcuenta(new Ahorro(sNumerodeCuenta,dSaldoInicial,c.GetiSaldoMinimo(),c.GetIntereses(),cTipo));
                }
                else if(cTipo == '2'){
                p[iId].agregarcuenta(new Cheques(sNumerodeCuenta,dSaldoInicial,c.GetdComision(),cTipo));
                }
            }
        }
    return p;
}
///This  function reads from a file all the number client from the clients
Cliente* leerclientes(int &iN)
{
    Cliente *p;
    int iX = 0;
    ifstream clientes("Clientes.txt");
    string sLinea;
    string sId;
    string sNombre;
    string sTelefono;
    string sEmail;
    string sContrasenia;
    while (clientes.eof() == false){
       getline(clientes,sLinea);
       iN++;
    }
    p = new Cliente[iN];
    clientes.close();
    clientes.open("Clientes.txt");
    while (clientes.eof() == false){
        clientes>>sId;
        getline(clientes,sNombre,'\t');
        clientes>>sTelefono;
        clientes>>sEmail;
        clientes>>sContrasenia;
        p[iX] = Cliente(sId,sNombre,sTelefono,sEmail,sContrasenia);
        iX++;
    }
    clientes.close();
    return p;
}
///This  function displays the menu of the Banking system
void  menucliente(){
    cout<<"MENU CLIENTE"<<endl;
    cout<<"1. Deposito"<<endl;
    cout<<"2. Retiro"<<endl;
    cout<<"3. Consulta Saldo Atual"<<endl;
    cout<<"4. Consultar transacciones"<<endl;
    cout<<"5. Genera estado de cuenta"<<endl;
    cout<<"6. Salir"<<endl;
}
/// This function execute the Banking system
void menu()
{
    int iN = 0;
    int iX = 0;
    Cliente* p;
    Configuracion c;
    double dTiempo = c.GetiTiempoBloqueo();
    char cBanco = 'a';
    c = leerconfiguracion();
    p = leerclientes(iN);
    p = leercuentas(p,iN,c);
    p = leertransacciones(p,iN);
    generarestadosdecliente(p,iN,c);
    string sUsuario;
    string sContrasenia;
    do{
    Fecha fecha;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"                      Bienvenido a BANCATEC "<<endl;
    cout<<endl;
    cout<<"                     FECHA : ";
    fecha.desplegarFecha();
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"Usuario: ";
    cin>>sUsuario;
    cout<<"Contrasenia: ";
    cin>>sContrasenia;
    Fecha fechaactual;
    int iSeg = fechaactual.GetiSeg();
    int iHora = fechaactual.GetiHora() * 3600;
    int iMin = fechaactual.GetiMin() * 60 ;
    int dHorabanco = iSeg + iHora + iMin;
    if (validarusuariocompleto(p,iN,sUsuario,sContrasenia,iX) == false){
        if(validarusuario(p,iN,sUsuario,iX) == true && validarcontrasenia(p,iN,sContrasenia,iX) == false){
            if((dHorabanco - p[iX].Getfechabloqueo())>=c.GetiTiempoBloqueo()){
                    p[iX].SetcActiva('a');
                    p[iX].SetOportunidad(3);
            }
            if(p[iX].GetcActiva() == 'a'){
                int iOpor;
                iOpor = p[iX].iGetOportunidad();
                iOpor--;
                p[iX].SetOportunidad(iOpor);
                if(iOpor == 0){
                    p[iX].SetcActiva('b');
                    cout<<"Su numero de cliente ha sido bloqueado se desbloqueara en determinado tiempo"<<endl;
                }
                else{
                    cout<<"Tienes "<<iOpor<<" oportunidades si no se bloqueara la cuenta"<<endl;
                }
            }
            else{
                cout<<"Esta cuenta esta bloqueada"<<endl;
            }
        }
        else{
            cout<<"Esta cuenta no existe"<<endl;
        }
     }
     if (validarusuariocompleto(p,iN,sUsuario,sContrasenia,iX)== true){
        if((dHorabanco - p[iX].Getfechabloqueo())>= c.GetiTiempoBloqueo()){
            p[iX].SetcActiva('a');
            p[iX].SetOportunidad(3);
        }
        if( p[iX].GetcActiva() == 'a'){
            p[iX].SetOportunidad(3);
            Cuenta* cuentas[15];
            int iCantidadCuentas;
            int iCuenta;
            p[iX].GetCuentas(cuentas,iCantidadCuentas);
            if(iCantidadCuentas == 0){
                cout<<"********************************"<<endl;
                cout<<"NO TIENE NINGUNA CUENTA BANCARIA"<<endl;
                cout<<"********************************"<<endl;
            }
            else{
                cout<<"-----ACCESO DE CUENTA------"<<endl;
                do{
                p[iX].desplegarCuentas();
                cout<<"ELIGE LA CUENTA QUE DISPONGAS"<<endl;
                cout<<"Cuenta : ";
                cin>>iCuenta;
                int iMenu;
                if(iCuenta>0 && iCuenta<=iCantidadCuentas+1){
                    do{
                    int iA = iCuenta-1;
                    cout<<endl;
                    cout<<"-----------SEA BIENVENIDO A SU CUENTA------------"<<endl;
                    cout<<"Cliente : "<<p[iX].GetsNombre()<<endl;
                    cout<<endl;
                    cuentas[iA]->desplegar();
                    menucliente();
                    cout<<"INTRODUCE LA ACCION A REALIZAR"<<endl;
                    cin>>iMenu;
                    if(iMenu == 1){
                        deposito(cuentas,iA);
                        p[iX].SetCuentas(cuentas,iCantidadCuentas);
                    }
                    if(iMenu == 2){
                        retiro(cuentas,iA,c);
                        p[iX].SetCuentas(cuentas,iCantidadCuentas);
                    }
                    if(iMenu == 3){
                        consultasaldo(cuentas,iA,c);
                        p[iX].SetCuentas(cuentas,iCantidadCuentas);
                    }
                    if(iMenu == 4){
                        vertransacciones(cuentas,iA);
                    }
                    if(iMenu == 5){
                        estadodecuenta(cuentas,iA,p,iX,c);
                    }
                    if(iMenu > 6){
                        cout<<"--------OPERACION INVALIDA---------"<<endl;
                    }
                    }while(iMenu != 6);
                }
                else{
                cout<<"ELIGE LA CUENTA QUE DISPONGAS"<<endl;
                }
                }while(iCuenta == 0 && iCuenta>iCantidadCuentas+2);
                }
            }
            else {
                cout<<"Esta cuenta esta bloqueada"<<endl;
            }
    }
    }while(cBanco == 'a');
}

int main()
{
    menu();
}


