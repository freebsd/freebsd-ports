--- lazpaint/lazpainttype.pas	2018-04-25 23:41:19.922862000 -0500
+++ lazpaint/lazpainttype.pas	2018-04-25 23:41:36.179325000 -0500
@@ -6,7 +6,7 @@
 
 uses
   Classes, SysUtils, Inifiles, BGRABitmap, BGRABitmapTypes, uconfig, uimage, utool, Forms, BGRALayers, Graphics, Menus,
-  uscripting, Dialogs, Controls
+  uscripting, Dialogs, LazUTF8, LazFileUtils, Controls
   {$IFDEF LINUX}, InterfaceBase{$ENDIF};
 
 const
