--- IlmImf/ImfFrameBuffer.h.orig	2018-08-10 01:34:58 UTC
+++ IlmImf/ImfFrameBuffer.h
@@ -48,14 +48,15 @@
 #include "ImfPixelType.h"
 #include "ImfExport.h"
 #include "ImfNamespace.h"
+#include "ImathBox.h"
 
 #include <map>
 #include <string>
+#include <cstdint>
 
 
 OPENEXR_IMF_INTERNAL_NAMESPACE_HEADER_ENTER
 
-
 //-------------------------------------------------------
 // Description of a single slice of the frame buffer:
 //
@@ -148,6 +149,36 @@ struct Slice
            double fillValue = 0.0,
            bool xTileCoords = false,
            bool yTileCoords = false);
+
+    // Does the heavy lifting of computing the base pointer for a slice,
+    // avoiding overflow issues with large origin offsets
+    //
+    // if xStride == 0, assumes sizeof(pixeltype)
+    // if yStride == 0, assumes xStride * ( w / xSampling )
+    static Slice Make(PixelType type,
+                      const void *ptr,
+                      const IMATH_NAMESPACE::V2i &origin,
+                      int64_t w,
+                      int64_t h,
+                      size_t xStride = 0,
+                      size_t yStride = 0,
+                      int xSampling = 1,
+                      int ySampling = 1,
+                      double fillValue = 0.0,
+                      bool xTileCoords = false,
+                      bool yTileCoords = false);
+    // same as above, just computes w and h for you
+    // from a data window
+    static Slice Make(PixelType type,
+                      const void *ptr,
+                      const IMATH_NAMESPACE::Box2i &dataWindow,
+                      size_t xStride = 0,
+                      size_t yStride = 0,
+                      int xSampling = 1,
+                      int ySampling = 1,
+                      double fillValue = 0.0,
+                      bool xTileCoords = false,
+                      bool yTileCoords = false);
 };
 
 
