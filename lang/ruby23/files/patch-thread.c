--- thread.c.orig	2016-11-05 02:44:06 UTC
+++ thread.c
@@ -466,8 +466,8 @@ rb_threadptr_unlock_all_locking_mutexes(
 void
 rb_thread_terminate_all(void)
 {
-    rb_thread_t *th = GET_THREAD(); /* main thread */
-    rb_vm_t *vm = th->vm;
+    rb_thread_t *volatile th = GET_THREAD(); /* main thread */
+    rb_vm_t *volatile vm = th->vm;
     volatile int sleeping = 0;
 
     if (vm->main_thread != th) {
