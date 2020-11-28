--- numba/np/ufunc/workqueue.c.orig	2020-11-07 23:26:52 UTC
+++ numba/np/ufunc/workqueue.c
@@ -27,7 +27,11 @@ race conditions.
 /* PThread */
 #include <pthread.h>
 #include <unistd.h>
-#include <alloca.h>
+#if defined(__FreeBSD__)
+#  include <stdlib.h>
+#else
+#  include <alloca.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #include <signal.h>
