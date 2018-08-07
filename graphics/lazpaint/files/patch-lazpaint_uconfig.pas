--- lazpaint/uconfig.pas	2018-04-25 23:39:35.445237000 -0500
+++ lazpaint/uconfig.pas	2018-04-25 23:39:48.185933000 -0500
@@ -5,7 +5,7 @@
 interface
 
 uses
-  Classes, SysUtils, IniFiles, BGRABitmapTypes, Graphics, LCLType, uscripting;
+  Classes, SysUtils, IniFiles, BGRABitmapTypes, Graphics, LCLType, uscripting, LazUTF8, LazUTF8Sysutils, LazFileUtils;
 
 type
   TLazPaintConfig = class;
