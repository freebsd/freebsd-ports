--- libs/aphex/src/aphex_thread.c.orig	Sat Nov 23 05:28:53 2002
+++ libs/aphex/src/aphex_thread.c	Tue Jan 14 08:40:17 2003
@@ -134,7 +134,11 @@
     pthread_mutex_init( &mutex->mutex, NULL );
 #else
     pthread_mutexattr_init( &mutex->attr );
+#if defined(__FreeBSD__)
+    pthread_mutexattr_setkind_np( &mutex->attr, PTHREAD_MUTEX_RECURSIVE );
+#else
     pthread_mutexattr_setkind_np( &mutex->attr, PTHREAD_MUTEX_RECURSIVE_NP );
+#endif
     pthread_mutex_init( &mutex->mutex, &mutex->attr );
 #endif
     mutex->recursive = 1;
