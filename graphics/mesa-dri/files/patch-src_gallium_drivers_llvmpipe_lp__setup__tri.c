--- src/gallium/drivers/llvmpipe/lp_setup_tri.c.orig	2022-10-11 18:53:31 UTC
+++ src/gallium/drivers/llvmpipe/lp_setup_tri.c
@@ -46,7 +46,9 @@
 #if defined(PIPE_ARCH_SSE)
 #include <emmintrin.h>
 #elif defined(_ARCH_PWR8) && UTIL_ARCH_LITTLE_ENDIAN
+#undef bool
 #include <altivec.h>
+#define bool _Bool
 #include "util/u_pwr8.h"
 #endif
 
