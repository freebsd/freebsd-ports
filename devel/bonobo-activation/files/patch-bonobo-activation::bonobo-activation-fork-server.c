--- bonobo-activation/bonobo-activation-fork-server.c.orig	Fri Oct 18 06:15:11 2002
+++ bonobo-activation/bonobo-activation-fork-server.c	Sat Oct 19 15:35:03 2002
@@ -364,6 +364,8 @@
 	} else if ((childpid = fork ())) {
 		_exit (0);	/* de-zombifier process, just exit */
 	} else {
+	    	sigprocmask (SIG_SETMASK, &omask, NULL);
+
 		setenv_activation_environment (environment);
 
 		if (od_iorstr != NULL) {
