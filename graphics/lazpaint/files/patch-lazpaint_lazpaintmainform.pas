--- lazpaint/lazpaintmainform.pas	2018-04-25 23:51:57.849654000 -0500
+++ lazpaint/lazpaintmainform.pas	2018-04-25 23:52:24.210190000 -0500
@@ -17,7 +17,7 @@
 
   LazPaintType, UMainFormLayout, UTool, UImage, UImageAction, ULayerAction, UZoom,
   UImageObservation, UConfig, UScaleDPI, UResourceStrings,
-  UMenu, uscripting, ubrowseimages, UToolPolygon, UBarUpDown;
+  UMenu, uscripting, ubrowseimages, UToolPolygon, UBarUpDown, LazFileUtils, LazUTF8;
 
 const
   MinPenWidthValue = 10;
