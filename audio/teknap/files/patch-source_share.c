--- source/share.c.orig	2007-11-12 15:41:18.000000000 +0100
+++ source/share.c	2007-11-12 15:43:42.000000000 +0100
@@ -38,7 +38,7 @@
 
 static pthread_mutex_t quit_mutex = PTHREAD_MUTEX_INITIALIZER;
 
-static pthread_mutex_t fserv_struct_mutex = PTHREAD_MUTEX_INITIALIZER;
+pthread_mutex_t fserv_struct_mutex = PTHREAD_MUTEX_INITIALIZER;
 pthread_mutex_t shared_count_mutex = PTHREAD_MUTEX_INITIALIZER;
 static void share_thread_signal_setup(void);
 
