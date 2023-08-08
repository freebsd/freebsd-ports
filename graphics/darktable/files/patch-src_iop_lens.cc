--- src/iop/lens.cc.orig	2022-12-14 15:18:18 UTC
+++ src/iop/lens.cc
@@ -59,7 +59,7 @@ extern "C" {
 
 #if LF_VERSION == ((0 << 24) | (3 << 16) | (95 << 8) | 0)
 #define LF_0395
-#error lensfun 0.3.95 is not supported since its API is not backward compatible with lensfun stable release.
+#pragma message("lensfun 0.3.95 is not supported since its API is not backward compatible with lensfun stable release.")
 #endif
 
 DT_MODULE_INTROSPECTION(6, dt_iop_lens_params_t)
