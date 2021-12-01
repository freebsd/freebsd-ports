--- ksw.c.orig	2021-12-01 13:48:35 UTC
+++ ksw.c
@@ -26,7 +26,9 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <assert.h>
-#include <emmintrin.h>
+// #include <emmintrin.h>
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 #include "ksw.h"
 
 #ifdef USE_MALLOC_WRAPPERS
