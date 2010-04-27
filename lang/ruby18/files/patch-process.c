--- process.c.orig	2010-04-27 01:11:32.000000000 -0700
+++ process.c	2010-04-27 01:11:39.000000000 -0700
@@ -920,7 +920,7 @@
 #endif
 
 #ifdef HAVE_SETITIMER
-#define before_exec() rb_thread_stop_timer()
+#define before_exec() rb_thread_stop_timer_fake()
 #define after_exec() rb_thread_start_timer()
 #else
 #define before_exec()
