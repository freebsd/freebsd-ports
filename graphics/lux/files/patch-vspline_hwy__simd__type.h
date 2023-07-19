--- vspline/hwy_simd_type.h.orig	2023-03-30 09:58:06 UTC
+++ vspline/hwy_simd_type.h
@@ -104,7 +104,9 @@
 #include <hwy/contrib/math/math-inl.h>
 #include <hwy/aligned_allocator.h>
 #include <hwy/print-inl.h>
+#ifndef HWY_HAVE_ATAN2
 #include "hwy_atan2.h"
+#endif
 
 // lux uses it's own dispatching mechanism, but this code should also
 // cooperate with highway's multi-platform strategy
@@ -694,7 +694,6 @@ PROMOTE(unsigned short,int)
 PROMOTE(unsigned char,int)
 PROMOTE(unsigned char,short)
 
-PROMOTE(short,unsigned int)
 PROMOTE(signed char,unsigned int)
 PROMOTE(unsigned short,unsigned int)
 PROMOTE(unsigned char,unsigned int)
