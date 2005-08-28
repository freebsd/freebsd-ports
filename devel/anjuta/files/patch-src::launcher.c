--- src/launcher.c.orig	Sun Apr 24 09:28:02 2005
+++ src/launcher.c	Wed Aug 17 02:33:34 2005
@@ -1130,9 +1130,9 @@ anjuta_launcher_fork (AnjutaLauncher *la
 		/* Set no delays for the write pipes (non_buffered) so
 		that we get all the outputs immidiately */
 		if ((md = fcntl (stdout_pipe[1], F_GETFL)) != -1)
-			fcntl (stdout_pipe[1], F_SETFL, O_SYNC | md);
+			fcntl (stdout_pipe[1], F_SETFL, O_FSYNC | md);
 		if ((md = fcntl (stderr_pipe[1], F_GETFL)) != -1)
-			fcntl (stderr_pipe[1], F_SETFL, O_SYNC | md);
+			fcntl (stderr_pipe[1], F_SETFL, O_FSYNC | md);
 		
 		execvp (args[0], args);
 		g_warning (_("Cannot execute command: \"%s\""), args[0]);
