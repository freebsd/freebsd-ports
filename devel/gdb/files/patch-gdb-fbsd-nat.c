--- gdb/fbsd-nat.c.orig	2016-08-01 17:50:20.000000000 +0200
+++ gdb/fbsd-nat.c	2016-12-14 23:23:39.467449000 +0100
@@ -680,6 +680,9 @@
   if (!ptid_match (tp->ptid, *filter))
     return 0;
 
+  if (tp->state == THREAD_EXITED) {
+    return 0;
+  }
   if (ptrace (PT_RESUME, ptid_get_lwp (tp->ptid), NULL, 0) == -1)
     perror_with_name (("ptrace"));
   return 0;
@@ -710,6 +713,14 @@
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
