--- libmicro.c.orig	2011-05-11 00:58:23 UTC
+++ libmicro.c
@@ -859,10 +859,14 @@ barrier_create(int hwm, int datasize)
 	b->ba_flag  = 0;
 
 	(void) pthread_mutexattr_init(&attr);
+#if !defined(__FreeBSD__)
 	(void) pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
+#endif
 
 	(void) pthread_condattr_init(&cattr);
+#if !defined(__FreeBSD__)
 	(void) pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_SHARED);
+#endif
 
 	(void) pthread_mutex_init(&b->ba_lock, &attr);
 	(void) pthread_cond_init(&b->ba_cv, &cattr);
