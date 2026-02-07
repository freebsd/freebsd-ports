--- Source/Globales.pas.orig	2021-08-01 06:56:07 UTC
+++ Source/Globales.pas
@@ -5,7 +5,7 @@ unit Globales;
 {$mode objfpc}{$H+}
 interface
 uses  Classes, SysUtils, Forms, SynEdit, SynEditKeyCmds, MisUtils,
-      lclType, FileUtil, LazLogger, Menus ;
+      lclType, FileUtil, LazLogger, Menus,Process, LazFileUtils, LazUTF8 ;
 
 const
   NOM_PROG = 'PicPas';   //nombre de programa
@@ -29,6 +29,7 @@ var
    archivoEnt  : string;    //archivo de entrada
    MostrarError: Boolean;   //Bandera para mostrar mensajesde error.
    ActConsSeg  : Boolean;   //Activa consultas en segundo plano
+   S: string;
 
 /////////////// Campos para manejo del diccionario //////////
 var
@@ -176,7 +177,11 @@ End;
 
 initialization
   //inicia directorios de la aplicación
-  patApp      :=  ExtractFilePath(Application.ExeName);  //incluye el '\' final
+  {$ifdef windows}
+  patApp := GetEnvironmentVariableUTF8('appdata')+'\PicPas\';
+  {$else}
+  patApp :=  GetEnvironmentVariableUTF8('HOME')+'/.config/PicPas/';
+  {$endif}
   patSamples  := patApp + 'samples';
   patUnits    := patApp + 'units';
   patTemp     := patApp + 'temp';
@@ -189,41 +194,107 @@ initialization
   archivoEnt  := '';    //archivo de entrada
   //verifica existencia de carpetas de trabajo
   try
+    if not DirectoryExists(patApp) then begin
+        CreateDir(patApp);
+    end;
     if not DirectoryExists(patSamples) then begin
        msgexc(WA_DIR_NOEXIST, [patSamples]);
-       CreateDir(patSamples);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '/usr/local/share/picpas/samples',
+        patSamples
+        ], S);
+      {else}
+        CreateDir(patSamples);
+      {$endif}
     end;
     if not DirectoryExists(patUnits) then begin
        msgexc(WA_DIR_NOEXIST, [patUnits]);
-       CreateDir(patUnits);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '/usr/local/share/picpas/units',
+        patUnits
+        ], S);
+      {else}
+        CreateDir(patUnits);
+      {$endif}
     end;
     if not DirectoryExists(patDevices10) then begin
        msgexc(WA_DIR_NOEXIST, [patDevices10]);
-       CreateDir(patDevices10);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '/usr/local/share/picpas/devices10',
+        patDevices10
+        ], S);
+      {else}
+        CreateDir(patDevices10);
+      {$endif}
     end;
     if not DirectoryExists(patDevices16) then begin
        msgexc(WA_DIR_NOEXIST, [patDevices16]);
-       CreateDir(patDevices16);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '/usr/local/share/picpas/devices16',
+        patDevices16
+        ], S);
+      {else}
+        CreateDir(patDevices16);
+      {$endif}
     end;
     if not DirectoryExists(patDevices17) then begin
        msgexc(WA_DIR_NOEXIST, [patDevices17]);
-       CreateDir(patDevices17);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '/usr/local/share/picpas/devices17',
+        patDevices17
+        ], S);
+      {else}
+        CreateDir(patDevices17);
+      {$endif}
     end;
     if not DirectoryExists(patDevices18) then begin
        msgexc(WA_DIR_NOEXIST, [patDevices18]);
-       CreateDir(patDevices18);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '/usr/local/share/picpas/devices18',
+        patDevices18
+        ], S);
+      {else}
+        CreateDir(patDevices18);
+      {$endif}
     end;
     if not DirectoryExists(patTemp) then begin
        msgexc(WA_DIR_NOEXIST, [patTemp]);
-       CreateDir(patTemp);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '/usr/local/share/picpas/temp',
+        patTemp
+        ], S);
+      {else}
+        CreateDir(patTemp);
+      {$endif}
     end;
     if not DirectoryExists(patSyntax) then begin
        msgexc(WA_DIR_NOEXIST, [patSyntax]);
-       CreateDir(patSyntax);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '/usr/local/share/picpas/syntax',
+        patSyntax
+        ], S);
+      {else}
+        CreateDir(patSyntax);
+      {$endif}
     end;
     if not DirectoryExists(patThemes) then begin
        msgexc(WA_DIR_NOEXIST, [patThemes]);
-      CreateDir(patThemes);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '/usr/local/share/picpas/themes',
+        patThemes
+        ], S);
+      {else}
+        CreateDir(patThemes);
+      {$endif}
     end;
 
   except
