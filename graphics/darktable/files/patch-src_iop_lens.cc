--- src/iop/lens.cc.orig	2024-07-17 15:29:39 UTC
+++ src/iop/lens.cc
@@ -66,7 +66,7 @@ extern "C" {
 
 #if LF_VERSION == ((0 << 24) | (3 << 16) | (95 << 8) | 0)
 #define LF_0395
-#error Lensfun 0.3.95 is not supported since its API is not backward compatible with Lensfun stable release.
+#pragma message("Lensfun 0.3.95 is not supported since its API is not backward compatible with Lensfun stable release.")
 #endif
 
 DT_MODULE_INTROSPECTION(10, dt_iop_lens_params_t)
