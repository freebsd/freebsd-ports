--- voice/libvoice/signal.c.orig	1999-10-23 21:58:01 UTC
+++ voice/libvoice/signal.c
@@ -34,23 +34,16 @@ static void signal_sigalrm(int sig)
 
 static void signal_sigchld(int sig)
      {
+     /*
+	This appears to break passing back the shells exitstatus to vgetty
+
      pid_t pid;
      int status;
-     pid = wait(&status); /* This appears to fix core dumps on HPUX. Maybe this
+     pid = wait(&status);*/ /* This appears to fix core dumps on HPUX. Maybe this
                            * also fixes the same problem on Solaris.
                            */
      signal(SIGCHLD, signal_sigchld);
-     if (status) {
-        lprintf(L_WARN, "%s: Got child %d exit status %d signal",
-                program_name,
-                pid,
-                status);
-     }
-     else {
-        lprintf(L_JUNK, "%s: Got child %d exit signal",
-                program_name,
-                pid);
-     }
+     lprintf(L_JUNK, "%s: Got child status change signal", program_name);
      queue_event(create_event(SIGNAL_SIGCHLD));
      }
 
