--- bonobo-activation/bonobo-activation-fork-server.c.orig	Tue Mar 12 09:23:47 2002
+++ bonobo-activation/bonobo-activation-fork-server.c	Tue Apr  2 18:27:40 2002
@@ -342,6 +342,8 @@
 	} else if ((childpid = fork ())) {
 		_exit (0);	/* de-zombifier process, just exit */
 	} else {
+		sigprocmask (SIG_SETMASK, &omask, NULL);
+
                 if (display != NULL) {
                         bonobo_activation_setenv ("DISPLAY", display);
                 }
