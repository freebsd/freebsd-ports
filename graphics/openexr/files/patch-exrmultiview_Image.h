--- exrmultiview/Image.h.orig	2018-08-10 01:35:00 UTC
+++ exrmultiview/Image.h
@@ -159,6 +159,8 @@ TypedImageChannel<T>::TypedImageChannel
     _ySampling (ySampling),
     _pixels (0, 0)
 {
+    if ( _xSampling < 1 || _ySampling < 1 )
+        throw IEX_NAMESPACE::ArgExc ("Invalid x/y sampling values");
     resize();
 }
 
@@ -201,14 +203,14 @@ TypedImageChannel<T>::slice () const
     const IMATH_NAMESPACE::Box2i &dw = image().dataWindow();
     int w = dw.max.x - dw.min.x + 1;
 
-    return IMF::Slice (pixelType(),
-		       (char *) (&_pixels[0][0] -
-				 dw.min.y / _ySampling * (w / _xSampling) -
-				 dw.min.x / _xSampling),
-		       sizeof (T),
-		       (w / _xSampling) * sizeof (T),
-		       _xSampling,
-		       _ySampling);
+    return IMF::Slice::Make (
+        pixelType(),
+        &_pixels[0][0],
+        dw,
+        sizeof(T),
+        (w / _xSampling) * sizeof (T),
+        _xSampling,
+        _ySampling);
 }
 
 
@@ -227,7 +229,9 @@ template <class T>
 void
 TypedImageChannel<T>::black ()
 {
-    memset(&_pixels[0][0],0,image().width()/_xSampling*image().height()/_ySampling*sizeof(T));
+    size_t nx = static_cast<size_t>( image().width() ) / static_cast<size_t>( _xSampling );
+    size_t ny = static_cast<size_t>( image().height() ) / static_cast<size_t>( _ySampling );
+    memset(&_pixels[0][0],0,nx*ny*sizeof(T));
 }
 
 
