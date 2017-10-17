--- gdb/fbsd-nat.c.orig 2017-09-14 09:28:17 UTC
+++ gdb/fbsd-nat.c
@@ -682,6 +682,14 @@ fbsd_resume (struct target_ops *ops,
       struct thread_info *tp;
       int request;
 
+#ifndef PT_LWP_EVENTS
+      /* When LWP events are not supported, a new thread might already be
+	 running that has not yet reported an event when GDB wishes to
+         only run a single thread.  Force an update of the thread list
+	 to ensure that any such threads are suspended before the process
+	 is resumed.  */
+      fbsd_add_threads (ptid_get_pid (ptid));
+#endif
       ALL_NON_EXITED_THREADS (tp)
         {
 	  if (ptid_get_pid (tp->ptid) != ptid_get_pid (ptid))
