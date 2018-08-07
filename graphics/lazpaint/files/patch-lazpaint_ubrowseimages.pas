--- lazpaint/ubrowseimages.pas	2018-04-25 23:50:38.459232000 -0500
+++ lazpaint/ubrowseimages.pas	2018-04-25 23:50:47.539703000 -0500
@@ -7,7 +7,7 @@
 uses
   Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs,
   ComCtrls, ExtCtrls, Buttons, StdCtrls, BGRAVirtualScreen, BGRABitmap,
-  BGRABitmapTypes, BGRAAnimatedGif, UMySLV, LazPaintType, Masks, LCLType;
+  BGRABitmapTypes, BGRAAnimatedGif, UMySLV, LazPaintType, Masks, LCLType, LazFileUtils;
 
 const
   MaxIconCacheCount = 512;
