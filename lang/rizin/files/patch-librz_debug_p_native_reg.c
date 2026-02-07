--- librz/debug/p/native/reg.c.orig	2024-04-12 00:53:53 UTC
+++ librz/debug/p/native/reg.c
@@ -60,6 +60,8 @@ static char *rz_debug_native_reg_profile(RzDebug *dbg)
 #include "reg/kfbsd-x64.h"
 #elif __aarch64__
 #include "reg/kfbsd-arm64.h"
+#elif __powerpc64__
+#include "reg/kfbsd-ppc64.h"
 #else
 #error "Unsupported BSD architecture"
 #endif
