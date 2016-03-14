--- gdb/fbsd-nat.c.orig	2016-03-14 00:00:11.831889802 +0100
+++ gdb/fbsd-nat.c	2016-03-14 00:04:35.906871361 +0100
@@ -471,6 +471,14 @@
 			ptid_get_tid (ptid));
   if (ptid_lwp_p (ptid))
     {
+#ifndef PT_LWP_EVENTS
+      /* When LWP events are not supported, a new thread might already be
+	 running that has not yet reported an event when GDB wishes to
+         only run a single thread.  Force an update of the thread list
+	 to ensure that any such threads are suspended before the process
+	 is resumed.  */
+      fbsd_add_threads (ptid_get_pid (ptid));
+#endif
       /* If ptid is a specific LWP, suspend all other LWPs in the process.  */
       iterate_over_threads (resume_one_thread_cb, &ptid);
     }
