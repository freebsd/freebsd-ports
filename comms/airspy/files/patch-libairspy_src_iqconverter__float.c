--- libairspy/src/iqconverter_float.c.orig	2018-06-27 04:58:05 UTC
+++ libairspy/src/iqconverter_float.c
@@ -39,7 +39,9 @@ THE SOFTWARE.
   #define _inline inline
   #define FIR_STANDARD
 #elif defined(__FreeBSD__)
+# if defined(FREEBSD_USE_SIMD)
   #define USE_SSE2
 #include <immintrin.h>
+# endif
   #define _inline inline
   #define _aligned_free(mem) free(mem)
