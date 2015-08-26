--- racket/include/scheme.h.orig	2015-07-28 14:12:13.879975000 -0700
+++ racket/include/scheme.h	2015-07-28 14:15:08.492462000 -0700
@@ -63,10 +63,12 @@
 # define MZ_USE_SINGLE_FLOATS
 #endif
 
+#if (__FreeBSD_version >= 1000100)
 /* gcc defines __SSE2_MATH__ when SSE2 floating point is enabled: */
 #ifdef __SSE2_MATH__
 # define C_COMPILER_USES_SSE 1
 #endif
+#endif
 
 #ifdef C_COMPILER_USES_SSE
 # if defined(MZ_TRY_EXTFLONUMS) && !defined(MZ_NO_EXTFLONUMS)
