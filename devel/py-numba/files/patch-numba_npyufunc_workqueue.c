--- numba/npyufunc/workqueue.c.orig	2018-11-14 22:14:35 UTC
+++ numba/npyufunc/workqueue.c
@@ -19,7 +19,11 @@ race condition.
 /* PThread */
 #include <pthread.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #define NUMBA_PTHREAD
 #endif
 
