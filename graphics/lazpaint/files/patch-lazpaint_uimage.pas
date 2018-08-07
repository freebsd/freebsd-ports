--- lazpaint/uimage.pas	2018-04-25 23:44:24.819000000 -0500
+++ lazpaint/uimage.pas	2018-04-25 23:44:47.194779000 -0500
@@ -7,7 +7,7 @@
 uses
   Classes, SysUtils, BGRABitmap, BGRABitmapTypes, types,
   UImageState, UStateType, Graphics, BGRALayers, UImageObservation, FPWriteBMP,
-  UImageType, BGRALzpCommon, UZoom;
+  UImageType, BGRALzpCommon, UZoom, LazUTF8;
 
 const
   MaxLayersToAdd = 99;
