--- src/iop/lens.cc.orig	2026-01-21 06:34:16.147824000 +0100
+++ src/iop/lens.cc	2026-01-21 06:34:30.978952000 +0100
@@ -62,7 +62,7 @@
 
 #if LF_VERSION >= ((0 << 24) | (3 << 16) | (95 << 8) | 0)
 #define LF_0395
-#error Lensfun 0.3.95 and later development snapshots are not supported.
+#pragma message("Lensfun 0.3.95 is not supported since its API is not backward compatible with Lensfun stable release.")
 #endif
 
 DT_MODULE_INTROSPECTION(10, dt_iop_lens_params_t)
