--- lazpaint/uobject3d.pas	2018-04-25 23:47:42.778665000 -0500
+++ lazpaint/uobject3d.pas	2018-04-25 23:47:53.371177000 -0500
@@ -8,7 +8,7 @@
   Classes, SysUtils, FileUtil, LResources, Forms, Controls, Graphics, Dialogs,
   StdCtrls, Spin, ExtCtrls, ComCtrls, BGRAVirtualScreen, BGRAKnob,
   BGRAImageList, BGRABitmap, BGRAScene3D, LazPaintType, BGRABitmapTypes,
-  UConfig;
+  UConfig, LazFileUtils;
 
 const
   AntialiasingLevelWhenFixed = 2;
