--- IlmImf/ImfFrameBuffer.cpp.orig	2018-08-10 01:34:58 UTC
+++ IlmImf/ImfFrameBuffer.cpp
@@ -74,6 +74,88 @@ Slice::Slice (PixelType t,
     // empty
 }
 
+Slice
+Slice::Make (
+    PixelType                   type,
+    const void*                 ptr,
+    const IMATH_NAMESPACE::V2i& origin,
+    int64_t                     w,
+    int64_t                     h,
+    size_t                      xStride,
+    size_t                      yStride,
+    int                         xSampling,
+    int                         ySampling,
+    double                      fillValue,
+    bool                        xTileCoords,
+    bool                        yTileCoords)
+{
+    char* base = reinterpret_cast<char*> (const_cast<void *> (ptr));
+    if (xStride == 0)
+    {
+        switch (type)
+        {
+            case UINT: xStride = sizeof (uint32_t); break;
+            case HALF: xStride = sizeof (uint16_t); break;
+            case FLOAT: xStride = sizeof (float); break;
+            case NUM_PIXELTYPES:
+                THROW (IEX_NAMESPACE::ArgExc, "Invalid pixel type.");
+        }
+    }
+    if (yStride == 0)
+        yStride = static_cast<size_t> (w / xSampling) * xStride;
+
+    // data window is an int, so force promote to higher type to avoid
+    // overflow for off y (degenerate size checks should be in
+    // ImfHeader::sanityCheck, but offset can be large-ish)
+    int64_t offx = (static_cast<int64_t> (origin.x) /
+                    static_cast<int64_t> (xSampling));
+    offx *= static_cast<int64_t> (xStride);
+
+    int64_t offy = (static_cast<int64_t> (origin.y) /
+                    static_cast<int64_t> (ySampling));
+    offy *= static_cast<int64_t> (yStride);
+
+    return Slice (
+        type,
+        base - offx - offy,
+        xStride,
+        yStride,
+        xSampling,
+        ySampling,
+        fillValue,
+        xTileCoords,
+        yTileCoords);
+}
+
+Slice
+Slice::Make (
+    PixelType                     type,
+    const void*                   ptr,
+    const IMATH_NAMESPACE::Box2i& dataWindow,
+    size_t                        xStride,
+    size_t                        yStride,
+    int                           xSampling,
+    int                           ySampling,
+    double                        fillValue,
+    bool                          xTileCoords,
+    bool                          yTileCoords)
+{
+    return Make (
+        type,
+        ptr,
+        dataWindow.min,
+        static_cast<int64_t> (dataWindow.max.x) -
+            static_cast<int64_t> (dataWindow.min.x) + 1,
+        static_cast<int64_t> (dataWindow.max.y) -
+            static_cast<int64_t> (dataWindow.min.y) + 1,
+        xStride,
+        yStride,
+        xSampling,
+        ySampling,
+        fillValue,
+        xTileCoords,
+        yTileCoords);
+}
 
 void
 FrameBuffer::insert (const char name[], const Slice &slice)
