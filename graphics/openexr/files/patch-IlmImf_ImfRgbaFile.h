--- IlmImf/ImfRgbaFile.h.orig	2018-08-10 01:34:58 UTC
+++ IlmImf/ImfRgbaFile.h
@@ -60,6 +60,65 @@
 
 OPENEXR_IMF_INTERNAL_NAMESPACE_HEADER_ENTER
 
+//-------------------------------------------------------
+// Utility to compute the origin-based pointer address
+//
+// With large offsets for the data window, the naive code
+// can wrap around, especially on 32-bit machines.
+// This can be used to avoid that
+//-------------------------------------------------------
+
+inline const Rgba *
+ComputeBasePointer (
+    const Rgba*                 ptr,
+    const IMATH_NAMESPACE::V2i& origin,
+    int64_t                     w,
+    size_t                      xStride = 1,
+    size_t                      yStride = 0)
+{
+    if (yStride == 0)
+        yStride = w;
+    int64_t offx = static_cast<int64_t> (origin.x);
+    offx *= xStride;
+    int64_t offy = static_cast<int64_t> (origin.y);
+    offy *= yStride;
+    return ptr - offx - offy;
+}
+
+inline const Rgba *
+ComputeBasePointer (const Rgba* ptr, const IMATH_NAMESPACE::Box2i& dataWindow)
+{
+    return ComputeBasePointer (ptr, dataWindow.min,
+                         static_cast<int64_t> (dataWindow.max.x) -
+                          static_cast<int64_t> (dataWindow.min.x) + 1);
+}
+
+inline Rgba*
+ComputeBasePointer (
+    Rgba*                       ptr,
+    const IMATH_NAMESPACE::V2i& origin,
+    int64_t                     w,
+    size_t                      xStride = 1,
+    size_t                      yStride = 0)
+{
+    if (yStride == 0)
+        yStride = w;
+    int64_t offx = static_cast<int64_t> (origin.x);
+    offx *= xStride;
+    int64_t offy = static_cast<int64_t> (origin.y);
+    offy *= yStride;
+    return ptr - offx - offy;
+}
+
+inline Rgba*
+ComputeBasePointer (Rgba* ptr, const IMATH_NAMESPACE::Box2i& dataWindow)
+{
+    return ComputeBasePointer (
+        ptr,
+        dataWindow.min,
+        static_cast<int64_t> (dataWindow.max.x) -
+            static_cast<int64_t> (dataWindow.min.x) + 1);
+}
 
 //
 // RGBA output file.
