--- src/launcher.c.orig	Wed Nov  5 21:50:36 2003
+++ src/launcher.c	Sat Nov  8 05:43:47 2003
@@ -23,10 +23,10 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <signal.h>
-#include <pty.h>
 #include <assert.h>
 #include <gnome.h>
 #include <termios.h>
+#include <vte/pty.h>
 
 #include "pixmaps.h"
 #include "launcher.h"
@@ -836,9 +836,9 @@
 		/* Set no delays for the write pipes (non_buffered) so
 		that we get all the outputs immidiately */
 		if ((md = fcntl (stdout_pipe[1], F_GETFL)) != -1)
-			fcntl (stdout_pipe[1], F_SETFL, O_SYNC | md);
+			fcntl (stdout_pipe[1], F_SETFL, O_FSYNC | md);
 		if ((md = fcntl (stderr_pipe[1], F_GETFL)) != -1)
-			fcntl (stderr_pipe[1], F_SETFL, O_SYNC | md);
+			fcntl (stderr_pipe[1], F_SETFL, O_FSYNC | md);
 		
 		execvp (args[0], args);
 		g_error (_("Cannot execute command shell"));
