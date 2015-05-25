--- src/stats.h.orig	2015-05-25 02:43:07.925981000 +0300
+++ src/stats.h	2015-05-25 02:43:18.075337000 +0300
@@ -1,6 +1,11 @@
 #ifndef STATS_H
 #define STATS_H
 
+#if defined(__FreeBSD__) 
+#include <sys/types.h>
+#include <machine/atomic.h>
+#endif /* defined(__FreeBSD__) */
+
 #include <stdbool.h>
 #include <stdint.h>
 
