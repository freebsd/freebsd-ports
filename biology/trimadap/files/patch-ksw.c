--- ksw.c.orig	2024-10-16 19:52:35 UTC
+++ ksw.c
@@ -26,7 +26,9 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
-#include <emmintrin.h>
+// #include <emmintrin.h>
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 #include "ksw.h"
 
 #ifdef __GNUC__
