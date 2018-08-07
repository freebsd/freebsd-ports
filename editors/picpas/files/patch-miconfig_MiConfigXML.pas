--- miconfig/MiConfigXML.pas	2018-04-26 21:42:01.343702000 -0500
+++ miconfig/MiConfigXML.pas	2018-04-26 21:43:20.791884000 -0500
@@ -20,7 +20,7 @@
 {$mode objfpc}{$H+}
 interface
 uses
-  Classes, SysUtils, Graphics, Forms, Laz2_XMLCfg, MisUtils, MiConfigBasic;
+  Classes, SysUtils, Graphics, Forms, Laz2_XMLCfg, MisUtils, MiConfigBasic, LazFileUtils, LazUTF8;
 type
   { TMiConfigXML }
   {Clase base que es usada para manejar los campos de configuración.}
@@ -75,7 +75,7 @@
 function TMiConfigXML.DefaultFileName: string;
 {Devuelve el nombre por defecto del archvio de configuración}
 begin
-  Result := ChangeFileExt(Application.ExeName,'.xml');
+  Result := ChangeFileExt(GetEnvironmentVariableUTF8('HOME')+'/.config/PicPas/'+Application.ExeName,'.xml');
 end;
 procedure TMiConfigXML.VerifyFile;
 //Verifica si el archivo XML "FileName" existe. Si no, muestra un mensaje y lo crea.
