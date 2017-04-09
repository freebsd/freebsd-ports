--- thread.c.orig	2016-11-11 22:33:21 UTC
+++ thread.c
@@ -462,8 +462,8 @@ rb_threadptr_unlock_all_locking_mutexes(
 void
 rb_thread_terminate_all(void)
 {
-    rb_thread_t *th = GET_THREAD(); /* main thread */
-    rb_vm_t *vm = th->vm;
+    rb_thread_t *volatile th = GET_THREAD(); /* main thread */
+    rb_vm_t *volatile vm = th->vm;
 
     if (vm->main_thread != th) {
 	rb_bug("rb_thread_terminate_all: called by child thread (%p, %p)",
