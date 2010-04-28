--- process.c.orig	2008-06-29 02:34:43.000000000 -0700
+++ process.c	2010-04-28 12:05:10.000000000 -0700
@@ -920,7 +920,11 @@
 #endif
 
 #ifdef HAVE_SETITIMER
+#if defined(_THREAD_SAFE)
+#define before_exec() rb_thread_stop_timer_fake()
+#else
 #define before_exec() rb_thread_stop_timer()
+#endif
 #define after_exec() rb_thread_start_timer()
 #else
 #define before_exec()
