--- src/gallium/drivers/llvmpipe/lp_rast_tri.c.orig	2022-10-11 18:53:31 UTC
+++ src/gallium/drivers/llvmpipe/lp_rast_tri.c
@@ -488,7 +488,9 @@ lp_rast_triangle_32_3_4(struct lp_rasterizer_task *tas
 
 #if defined(_ARCH_PWR8) && UTIL_ARCH_LITTLE_ENDIAN
 
+#undef bool
 #include <altivec.h>
+#define bool _Bool
 #include "util/u_pwr8.h"
 
 static inline void
