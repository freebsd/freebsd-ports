--- libgamin/gam_data.c.orig	Thu May 19 20:55:27 2005
+++ libgamin/gam_data.c	Thu May 19 20:55:45 2005
@@ -471,7 +471,7 @@
     }
     if (is_threaded > 0) {
 	pthread_mutexattr_init(&attr);
-	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
+	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 	pthread_mutex_init(&ret->lock, &attr);
 	pthread_mutexattr_destroy(&attr);
     }
