--- ./src/knot/server/dthreads.h.orig	2012-05-17 18:14:06.000000000 +0900
+++ ./src/knot/server/dthreads.h	2012-05-17 20:44:41.000000000 +0900
@@ -40,6 +40,11 @@
 #define _KNOTD_DTHREADS_H_
 
 #include <pthread.h>
+#ifdef HAVE_PTHREAD_SETAFFINITY_NP
+# if defined(__FreeBSD__)
+#include <pthread_np.h>
+# endif
+#endif
 
 /* Forward decls */
 struct dthread_t;