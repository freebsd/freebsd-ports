--- bonobo-activation/bonobo-activation-fork-server.c.orig	Wed Jul 24 16:46:27 2002
+++ bonobo-activation/bonobo-activation-fork-server.c	Wed Jul 24 16:47:00 2002
@@ -349,6 +349,8 @@
 	} else if ((childpid = fork ())) {
 		_exit (0);	/* de-zombifier process, just exit */
 	} else {
+	    	sigprocmask (SIG_SETMASK, &omask, NULL);
+
                 if (display != NULL) {
                         bonobo_activation_setenv ("DISPLAY", display);
                 }
