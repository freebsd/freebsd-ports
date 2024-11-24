--- ksw.c.orig	2024-11-22 18:42:53 UTC
+++ ksw.c
@@ -27,7 +27,9 @@
 #include <stdint.h>
 #include <assert.h>
 #if defined __SSE2__
-#include <emmintrin.h>
+// #include <emmintrin.h>
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 #elif defined __ARM_NEON
 #include "neon_sse.h"
 #else
