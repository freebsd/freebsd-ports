--- mutex.c.orig	Sat Aug  6 14:17:43 2005
+++ mutex.c	Sat Aug  6 14:18:26 2005
@@ -125,9 +125,11 @@
 		errors++;
 	} else {
 		(void) pthread_mutexattr_init(&attr);
+#if !defined(__FreeBSD__)
 		if (optp)
 			(void) pthread_mutexattr_setpshared(&attr,
 			    PTHREAD_PROCESS_SHARED);
+#endif
 
 		if (pthread_mutex_init(lock, &attr) != 0)
 			errors++;
