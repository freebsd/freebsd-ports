--- exrmaketiled/Image.h.orig	2018-08-10 01:35:00 UTC
+++ exrmaketiled/Image.h
@@ -190,12 +190,12 @@ OPENEXR_IMF_INTERNAL_NAMESPACE::Slice
 TypedImageChannel<T>::slice () const
 {
     const IMATH_NAMESPACE::Box2i &dw = image().dataWindow();
-    int w = dw.max.x - dw.min.x + 1;
 
-    return OPENEXR_IMF_INTERNAL_NAMESPACE::Slice (pixelType(),
-		       (char *) (&_pixels[0][0] - dw.min.y * w - dw.min.x),
-		       sizeof (T),
-		       w * sizeof (T));
+    return OPENEXR_IMF_INTERNAL_NAMESPACE::Slice::Make (
+        pixelType(),
+        &_pixels[0][0],
+        dw,
+        sizeof (T));
 }
 
 
