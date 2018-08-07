--- lazpaint/umyslv.pas	2018-04-25 23:49:08.994450000 -0500
+++ lazpaint/umyslv.pas	2018-04-25 23:49:18.561675000 -0500
@@ -6,7 +6,7 @@
 
 uses
   Classes, Types, SysUtils, ComCtrls, ShellCtrls, Controls, Graphics, BGRABitmap,
-  BGRAVirtualScreen, BGRABitmapTypes, UVolatileScrollBar;
+  BGRAVirtualScreen, BGRABitmapTypes, UVolatileScrollBar, LazFileUtils;
 
 type
   PMyShellListViewItemData = ^TMyShellListViewItemData;
