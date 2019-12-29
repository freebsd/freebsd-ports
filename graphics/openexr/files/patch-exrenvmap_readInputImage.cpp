--- exrenvmap/readInputImage.cpp.orig	2018-08-10 01:35:00 UTC
+++ exrenvmap/readInputImage.cpp
@@ -194,7 +194,7 @@ readSixImages (const char inFileName[],
                    "from the data window of other cube faces.");
         }
 
-        in.setFrameBuffer (pixels - dw.min.x - dw.min.y * w, 1, w);
+        in.setFrameBuffer (ComputeBasePointer (pixels, dw), 1, w);
         in.readPixels (dw.min.y, dw.max.y);
 
         pixels += w * h;
