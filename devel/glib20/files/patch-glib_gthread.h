--- glib/gthread.h.orig	Sat Jul 24 15:31:32 2004
+++ glib/gthread.h	Sat Jul 24 15:32:10 2004
@@ -202,7 +202,7 @@
 #define g_thread_yield()              G_THREAD_CF (thread_yield, (void)0, ())
 
 #define g_thread_create(func, data, joinable, error)			\
-  (g_thread_create_full (func, data, 0, joinable, FALSE, 		\
+  (g_thread_create_full (func, data, 1024*256, joinable, FALSE, 		\
                          G_THREAD_PRIORITY_NORMAL, error))
 
 GThread* g_thread_create_full  (GThreadFunc            func,
