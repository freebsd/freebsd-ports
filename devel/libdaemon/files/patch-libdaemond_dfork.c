--- libdaemon/dfork.c.orig	Mon Oct 17 22:58:04 2005
+++ libdaemon/dfork.c	Mon Oct 17 23:11:36 2005
@@ -209,7 +209,7 @@
 	    signal(SIGTSTP, SIG_IGN);
 	    
 	    setsid();
-	    setpgrp();
+	    setpgrp(0, getpid());
             
 	    if ((tty_fd = open("/dev/tty", O_RDWR)) >= 0) {
 		ioctl(tty_fd, TIOCNOTTY, NULL);
