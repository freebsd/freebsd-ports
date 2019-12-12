--- src/lib/evas/common/evas_cpu.c.orig	2019-11-25 13:47:47 UTC
+++ src/lib/evas/common/evas_cpu.c
@@ -10,6 +10,9 @@
 #if defined BUILD_SSE3
 #include <immintrin.h>
 #endif
+#if defined BUILD_ALTIVEC
+#include <altivec.h>
+#endif
 
 #if defined (HAVE_STRUCT_SIGACTION) && defined (HAVE_SIGLONGJMP)
 #include <signal.h>
