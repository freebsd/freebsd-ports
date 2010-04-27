--- intern.h.orig	2010-04-27 01:11:20.000000000 -0700
+++ intern.h	2010-04-27 01:11:30.000000000 -0700
@@ -209,6 +209,7 @@
 void rb_gc_mark_threads _((void));
 void rb_thread_start_timer _((void));
 void rb_thread_stop_timer _((void));
+void rb_thread_stop_timer_fake _((void));
 void rb_thread_schedule _((void));
 void rb_thread_wait_fd _((int));
 int rb_thread_fd_writable _((int));
