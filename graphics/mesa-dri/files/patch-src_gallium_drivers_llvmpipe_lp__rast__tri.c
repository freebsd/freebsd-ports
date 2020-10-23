--- src/gallium/drivers/llvmpipe/lp_rast_tri.c.orig	2020-09-28 22:52:10 UTC
+++ src/gallium/drivers/llvmpipe/lp_rast_tri.c
@@ -465,6 +465,11 @@ lp_rast_triangle_32_3_4(struct lp_rasterizer_task *tas
 
 #if defined(_ARCH_PWR8) && UTIL_ARCH_LITTLE_ENDIAN
 
+#ifdef __clang__
+#undef vector
+#undef pixel
+#undef bool
+#endif
 #include <altivec.h>
 #include "util/u_pwr8.h"
 
