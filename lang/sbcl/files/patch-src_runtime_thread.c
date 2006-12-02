--- src/runtime/thread.c	Thu Nov 23 15:11:26 2006 +0000
+++ src/runtime/thread.c	Fri Nov 24 01:54:54 2006 +0900
@@ -350,6 +350,10 @@ create_thread_struct(lispobj initial_fun
     int i;
 #endif
 
+#ifdef CREATE_CLEANUP_THREAD
+    /* Give a chance for cleanup threads to run. */
+    sched_yield();
+#endif
     /* may as well allocate all the spaces at once: it saves us from
      * having to decide what to do if only some of the allocations
      * succeed */
