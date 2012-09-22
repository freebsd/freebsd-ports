--- thread_pthread.c.orig	2012-09-20 00:26:58.000000000 -0700
+++ thread_pthread.c	2012-09-20 00:27:17.000000000 -0700
@@ -248,6 +248,7 @@
 #endif
 
     r = pthread_cond_init(&cond->cond, &attr);
+    pthread_condattr_destroy(&attr);
     if (r != 0) {
 	rb_bug_errno("pthread_cond_init", r);
     }
