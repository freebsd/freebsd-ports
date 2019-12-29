--- exrmakepreview/makePreview.cpp.orig	2018-08-10 01:35:00 UTC
+++ exrmakepreview/makePreview.cpp
@@ -110,7 +110,7 @@ generatePreview (const char inFileName[],
     int h = dw.max.y - dw.min.y + 1;
 
     Array2D <Rgba> pixels (h, w);
-    in.setFrameBuffer (&pixels[0][0] - dw.min.y * w - dw.min.x, 1, w);
+    in.setFrameBuffer (ComputeBasePointer (&pixels[0][0], dw), 1, w);
     in.readPixels (dw.min.y, dw.max.y);
 
     //
