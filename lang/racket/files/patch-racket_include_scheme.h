
$FreeBSD$

--- racket/include/scheme.h.orig
+++ racket/include/scheme.h
@@ -63,10 +63,12 @@
 # define MZ_USE_SINGLE_FLOATS
 #endif
 
+#if (__FreeBSD_version >= 1000100)
 /* gcc defines __SSE_MATH__ when SSE floating point is enabled: */
 #ifdef __SSE_MATH__
 # define C_COMPILER_USES_SSE 1
 #endif
+#endif
 
 #ifdef C_COMPILER_USES_SSE
 # if defined(MZ_TRY_EXTFLONUMS) && !defined(MZ_NO_EXTFLONUMS)
