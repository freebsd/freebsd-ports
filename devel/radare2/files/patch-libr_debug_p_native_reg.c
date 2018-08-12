--- libr/debug/p/native/reg.c.orig	2018-07-02 11:14:27 UTC
+++ libr/debug/p/native/reg.c
@@ -47,6 +47,8 @@ static char *r_debug_native_reg_profile(RDebug *dbg) {
 #include "reg/kfbsd-x86.h"
 #elif __x86_64__ || __amd64__
 #include "reg/kfbsd-x64.h"
+#elif __aarch64__
+#include "reg/kfbsd-arm64.h"
 #else
 #error "Unsupported BSD architecture"
 #endif
