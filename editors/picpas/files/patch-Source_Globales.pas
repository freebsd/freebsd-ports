--- Source/Globales.pas	2018-04-26 21:02:54.473902000 -0500
+++ Source/Globales.pas	2018-04-26 21:05:05.270945000 -0500
@@ -5,7 +5,7 @@
 {$mode objfpc}{$H+}
 interface
 uses  Classes, SysUtils, Forms, SynEdit, SynEditKeyCmds, MisUtils,
-      lclType, FileUtil, LazLogger, Menus ;
+      lclType, FileUtil, LazLogger, Menus, Process, LazFileUtils, LazUTF8;
 
 const
   NOM_PROG = 'PicPas';   //nombre de programa
@@ -26,6 +26,7 @@
    archivoEnt  : string;    //archivo de entrada
    MostrarError: Boolean;   //Bandera para mostrar mensajesde error.
    ActConsSeg  : Boolean;   //Activa consultas en segundo plano
+   S: string;
 
 /////////////// Campos para manejo del diccionario //////////
 var
@@ -173,7 +174,11 @@
 
 initialization
   //inicia directorios de la aplicación
-  patApp :=  ExtractFilePath(Application.ExeName);  //incluye el '\' final
+  {$ifdef windows}
+  patApp := GetEnvironmentVariableUTF8('appdata')+'\PicPas\';
+  {$else}
+  patApp :=  GetEnvironmentVariableUTF8('HOME')+'/.config/PicPas/';
+  {$endif}
   patSamples := patApp + 'samples';
   patUnits   := patApp + 'units';
   patDevices := patApp + 'devices';
@@ -183,29 +188,74 @@
   archivoEnt := '';    //archivo de entrada
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
+        '%%DATADIR%%/samples',
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
+        '%%DATADIR%%/units',
+        patUnits
+        ], S);
+      {else}
+        CreateDir(patUnits);
+      {$endif}
     end;
     if not DirectoryExists(patDevices) then begin
        msgexc(WA_DIR_NOEXIST, [patDevices]);
-       CreateDir(patDevices);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '%%DATADIR%%/devices',
+        patDevices
+        ], S);
+      {else}
+        CreateDir(patDevices);
+      {$endif}
     end;
     if not DirectoryExists(patTemp) then begin
        msgexc(WA_DIR_NOEXIST, [patTemp]);
-       CreateDir(patTemp);
+      {$ifdef freebsd}
+       RunCommand('cp', ['-R',
+        '%%DATADIR%%/temp',
+        patSamples
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
+        '%%DATADIR%%/syntax',
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
+        '%%DATADIR%%/themes',
+        patThemes
+        ], S);
+      {else}
+        CreateDir(patThemes);
+      {$endif}
     end;
 
   except
