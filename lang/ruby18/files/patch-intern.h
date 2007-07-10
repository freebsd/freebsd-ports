--- intern.h.orig	Sun Mar 11 11:31:53 2007
+++ intern.h	Thu Jun  7 16:40:01 2007
@@ -204,10 +204,13 @@
 void rb_thread_polling _((void));
 void rb_thread_sleep _((int));
 void rb_thread_sleep_forever _((void));
+enum thread_status rb_thread_status _((VALUE));
 VALUE rb_thread_stop _((void));
 VALUE rb_thread_wakeup _((VALUE));
+VALUE rb_thread_wakeup_alive _((VALUE));
 VALUE rb_thread_run _((VALUE));
 VALUE rb_thread_kill _((VALUE));
+VALUE rb_thread_alive_p _((VALUE));
 VALUE rb_thread_create _((VALUE (*)(ANYARGS), void*));
 void rb_thread_interrupt _((void));
 void rb_thread_trap_eval _((VALUE, int, int));
