--- bonobo-activation/bonobo-activation-fork-server.c.orig	Fri Nov  8 03:19:52 2002
+++ bonobo-activation/bonobo-activation-fork-server.c	Fri Nov  8 03:20:04 2002
@@ -396,6 +396,8 @@
 	} else if ((childpid = fork ())) {
 		_exit (0);	/* de-zombifier process, just exit */
 	} else {
+	    	sigprocmask (SIG_SETMASK, &omask, NULL);
+
 		if (display)
 			bonobo_activation_setenv ("DISPLAY", display);
 		if (session_manager)
