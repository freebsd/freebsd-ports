--- src/unix.c
+++ src/unix.c
@@ -211,8 +211,19 @@ static void set_process_group (void)
      {
 	pid_t pid = getpid ();
 	Startup_PGID = getpgid (pid);
-	(void) tcsetpgrp (Read_FD, pid);
-	(void) setpgid (pid, pid);
+	if (-1 == tcsetpgrp (Read_FD, pid))
+	  {
+	     fprintf (stderr, "tcsetpgrp failed\n");
+	     Terminal_PGID = -1;
+	     return;
+	  }
+	if (-1 == setpgid (pid, pid))
+	  {
+	     fprintf (stderr, "setpgid failed\n");
+	     (void) tcsetpgrp (Read_FD, Startup_PGID);
+	     Terminal_PGID = -1;
+	     return;
+	  }
      }
 #endif
 }
