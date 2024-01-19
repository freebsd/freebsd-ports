--- MACS3/fermi-lite/ksw.c.orig	2023-11-15 16:09:23 UTC
+++ MACS3/fermi-lite/ksw.c
@@ -28,7 +28,7 @@
 
 /* I modified this according to https://github.com/lh3/bwa/pull/283/*/
 #ifdef USE_SIMDE
-#include "lib/x86/sse2.h"
+#include <simde/x86/sse2.h>
 #else
 #include <emmintrin.h>
 #endif
