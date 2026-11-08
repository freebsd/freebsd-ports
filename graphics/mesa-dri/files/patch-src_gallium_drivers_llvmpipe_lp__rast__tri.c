--- src/gallium/drivers/llvmpipe/lp_rast_tri.c.orig	2026-08-05 21:14:26 UTC
+++ src/gallium/drivers/llvmpipe/lp_rast_tri.c
@@ -39,7 +39,9 @@
 #include <emmintrin.h>
 #include "util/u_sse.h"
 #elif defined(_ARCH_PWR8) && UTIL_ARCH_LITTLE_ENDIAN
+#undef bool
 #include <altivec.h>
+#define bool _Bool
 #include "util/u_pwr8.h"
 #endif
 
