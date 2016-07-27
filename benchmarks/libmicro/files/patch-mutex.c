--- mutex.c.orig	2011-05-11 00:58:23 UTC
+++ mutex.c
@@ -121,9 +121,11 @@ benchmark_initrun()
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
