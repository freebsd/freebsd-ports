--- aws-crt-ffi/crt/s2n/utils/s2n_fork_detection.c.orig	2022-07-30 03:57:28 UTC
+++ aws-crt-ffi/crt/s2n/utils/s2n_fork_detection.c
@@ -25,6 +25,10 @@
     #define _GNU_SOURCE
 #endif
 
+#if !defined(__BSD_VISIBLE)
+#define __BSD_VISIBLE 1
+#endif
+
 #include <sys/mman.h>
 
 /* Not always defined for Darwin */
