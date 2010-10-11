--- thread_pthread.c.orig	2010-10-10 03:11:47.000000000 -0700
+++ thread_pthread.c	2010-10-10 03:13:05.000000000 -0700
@@ -809,7 +809,7 @@
 	int err;
 
 	pthread_attr_init(&attr);
-#ifdef PTHREAD_STACK_MIN
+#if defined(PTHREAD_STACK_MIN) && !defined(__FreeBSD__)
 	pthread_attr_setstacksize(&attr,
 				  PTHREAD_STACK_MIN + (THREAD_DEBUG ? BUFSIZ : 0));
 #endif
