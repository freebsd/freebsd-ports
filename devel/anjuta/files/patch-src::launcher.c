--- src/launcher.c.orig	Thu Nov 27 17:37:16 2003
+++ src/launcher.c	Tue Dec  9 15:27:12 2003
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
@@ -845,9 +845,9 @@
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
@@ -902,7 +902,7 @@
 					ECHOCTL | ISIG | ICANON | IEXTEN | NOFLSH | TOSTOP);
 //	termios_flags.c_lflag |= 0;
 	termios_flags.c_cc[VMIN] = 0;
-	cfsetospeed(&termios_flags, __MAX_BAUD);
+	cfsetospeed(&termios_flags, B115200);
 	tcsetattr(pty_master_fd, TCSANOW, &termios_flags);
 
 	launcher->priv->stdout_watch = 
