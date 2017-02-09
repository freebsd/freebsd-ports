--- lib/ortho/trapezoid.c.orig	2016-09-20 04:45:02 UTC
+++ lib/ortho/trapezoid.c
@@ -30,6 +30,11 @@
 #define log2(x)  (log(x)/log(2))
 #endif
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704101 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x)  (log(x)/log(2))
+#endif
+
 /* Node types */
 
 #define T_X     1
