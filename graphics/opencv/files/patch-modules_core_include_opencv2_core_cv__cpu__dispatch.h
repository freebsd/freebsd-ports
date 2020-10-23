--- modules/core/include/opencv2/core/cv_cpu_dispatch.h.orig	2020-10-23 01:17:26 UTC
+++ modules/core/include/opencv2/core/cv_cpu_dispatch.h
@@ -108,10 +108,10 @@
 #endif
 
 #if defined(__VSX__) && defined(__PPC64__) && defined(__LITTLE_ENDIAN__)
-#  include <altivec.h>
 #  undef vector
 #  undef pixel
 #  undef bool
+#  include <altivec.h>
 #  define CV_VSX 1
 #endif
 
@@ -152,10 +152,10 @@ struct VZeroUpperGuard {
 #  include <arm_neon.h>
 #  define CV_NEON 1
 #elif defined(__VSX__) && defined(__PPC64__) && defined(__LITTLE_ENDIAN__)
-#  include <altivec.h>
 #  undef vector
 #  undef pixel
 #  undef bool
+#  include <altivec.h>
 #  define CV_VSX 1
 #endif
 
