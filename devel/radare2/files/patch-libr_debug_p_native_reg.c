--- libr/debug/p/native/reg.c.orig	2022-02-18 15:57:33 UTC
+++ libr/debug/p/native/reg.c
@@ -49,6 +49,12 @@ static char *r_debug_native_reg_profile(RDebug *dbg) {
 #include "reg/kfbsd-x64.h"
 #elif __aarch64__
 #include "reg/kfbsd-arm64.h"
+#elif __powerpc64__
+#include "reg/kfbsd-ppc64.h"
+#elif __powerpc__
+#include "reg/kfbsd-ppc.h"
+#elif __riscv
+#include "reg/kfbsd-riscv64.h"
 #else
 #error "Unsupported BSD architecture"
 #endif
