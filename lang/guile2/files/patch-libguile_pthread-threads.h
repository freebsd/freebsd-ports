--- libguile/pthread-threads.h.orig	2012-07-02 09:28:13 UTC
+++ libguile/pthread-threads.h
@@ -27,6 +27,9 @@
 */
 
 #include <pthread.h>
+#if HAVE_PTHREAD_NP_H
+# include <pthread_np.h>
+#endif
 #include <sched.h>
 
 /* `libgc' defines wrapper procedures for pthread calls.  */
