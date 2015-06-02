--- libguile/pthread-threads.h.orig	2010-12-13 17:24:40 UTC
+++ libguile/pthread-threads.h
@@ -26,6 +26,9 @@
 */
 
 #include <pthread.h>
+#if HAVE_PTHREAD_NP_H
+# include <pthread_np.h>
+#endif
 #include <sched.h>
 
 /* Threads 
