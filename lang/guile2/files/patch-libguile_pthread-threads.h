--- libguile/pthread-threads.h	2008-02-27 10:31:41.564950412 -0600
+++ libguile/pthread-threads.h	2008-02-27 10:36:08.383652510 -0600
@@ -26,6 +26,9 @@
 */
 
 #include <pthread.h>
+#if HAVE_PTHREAD_NP_H
+# include <pthread_np.h>
+#endif
 #include <sched.h>
 
 /* Threads 
