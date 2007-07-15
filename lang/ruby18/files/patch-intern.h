--- intern.h.orig	Sun Mar 11 11:31:53 2007
+++ intern.h	Sun Jul 15 13:26:46 2007
@@ -206,8 +206,10 @@
 void rb_thread_sleep_forever _((void));
 VALUE rb_thread_stop _((void));
 VALUE rb_thread_wakeup _((VALUE));
+VALUE rb_thread_wakeup_alive _((VALUE));
 VALUE rb_thread_run _((VALUE));
 VALUE rb_thread_kill _((VALUE));
+VALUE rb_thread_alive_p _((VALUE));
 VALUE rb_thread_create _((VALUE (*)(ANYARGS), void*));
 void rb_thread_interrupt _((void));
 void rb_thread_trap_eval _((VALUE, int, int));
