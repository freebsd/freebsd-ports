--- bonobo-activation/bonobo-activation-fork-server.c.orig	Tue Oct 29 05:51:18 2002
+++ bonobo-activation/bonobo-activation-fork-server.c	Tue Oct 29 19:24:23 2002
@@ -396,6 +396,8 @@
 	} else if ((childpid = fork ())) {
 		_exit (0);	/* de-zombifier process, just exit */
 	} else {
+	    	sigprocmask (SIG_SETMASK, &omask, NULL);
+
 		if (display)
 			bonobo_activation_setenv ("DISPLAY", display);
 		if (session_manager)
