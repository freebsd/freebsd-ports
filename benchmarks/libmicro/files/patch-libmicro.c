--- libmicro.c.orig	Sat Aug  6 14:15:04 2005
+++ libmicro.c	Sat Aug  6 14:15:52 2005
@@ -854,10 +854,14 @@
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
