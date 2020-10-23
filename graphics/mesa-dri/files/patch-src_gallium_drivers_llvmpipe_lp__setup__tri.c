--- src/gallium/drivers/llvmpipe/lp_setup_tri.c.orig	2020-10-22 23:39:01 UTC
+++ src/gallium/drivers/llvmpipe/lp_setup_tri.c
@@ -47,6 +47,11 @@
 #if defined(PIPE_ARCH_SSE)
 #include <emmintrin.h>
 #elif defined(_ARCH_PWR8) && UTIL_ARCH_LITTLE_ENDIAN
+#ifdef __clang__
+#undef vector
+#undef pixel
+#undef bool
+#endif
 #include <altivec.h>
 #include "util/u_pwr8.h"
 #endif
