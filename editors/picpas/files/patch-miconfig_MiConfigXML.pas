--- miconfig/MiConfigXML.pas.orig	2021-08-01 06:56:07 UTC
+++ miconfig/MiConfigXML.pas
@@ -20,7 +20,7 @@ unit MiConfigXML;
 {$mode objfpc}{$H+}
 interface
 uses
-  Classes, SysUtils, Graphics, Forms, Laz2_XMLCfg, MisUtils, MiConfigBasic;
+  Classes, SysUtils, Graphics, Forms, Laz2_XMLCfg, MisUtils, MiConfigBasic, LazFileUtils, LazUTF8;
 type
   { TMiConfigXML }
   {Clase base que es usada para manejar los campos de configuración.}
@@ -75,7 +75,7 @@ end;
 function TMiConfigXML.DefaultFileName: string;
 {Devuelve el nombre por defecto del archvio de configuración}
 begin
-  Result := ChangeFileExt(Application.ExeName,'.xml');
+  Result := ChangeFileExt(GetEnvironmentVariableUTF8('HOME')+'/.config/PicPas/'+Application.ExeName,'.xml');
 end;
 procedure TMiConfigXML.VerifyFile;
 //Verifica si el archivo XML "FileName" existe. Si no, muestra un mensaje y lo crea.
