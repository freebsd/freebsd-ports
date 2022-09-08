--- lib/igt_core.h.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_core.h
@@ -31,7 +31,9 @@
 #define IGT_CORE_H
 
 #include <assert.h>
+#ifdef __linux__
 #include <byteswap.h>
+#endif
 #include <setjmp.h>
 #include <stdbool.h>
 #include <stdint.h>
@@ -47,6 +49,10 @@
 #define IGT_LOG_DOMAIN (NULL)
 #endif
 
+#ifdef __FreeBSD__
+#include <signal.h>
+#define	jmp_buf	sigjmp_buf
+#endif
 
 #ifndef STATIC_ANALYSIS_BUILD
 #if defined(__clang_analyzer__) || defined(__COVERITY__) || defined(__KLOCWORK__)
