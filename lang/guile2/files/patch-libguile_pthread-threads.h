--- libguile/pthread-threads.h.orig	2011-11-22 10:55:14 UTC
+++ libguile/pthread-threads.h
@@ -27,6 +27,9 @@
 */
 
 #include <pthread.h>
+#if HAVE_PTHREAD_NP_H
+# include <pthread_np.h>
+#endif
 #include <sched.h>
 
 /* Threads 
