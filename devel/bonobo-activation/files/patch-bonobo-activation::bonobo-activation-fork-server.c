
$FreeBSD$

--- bonobo-activation/bonobo-activation-fork-server.c	2002/02/14 01:06:52	1.1
+++ bonobo-activation/bonobo-activation-fork-server.c	2002/02/14 01:07:07
@@ -270,6 +270,8 @@
 	} else if ((childpid = fork ())) {
 		_exit (0);	/* de-zombifier process, just exit */
 	} else {
+		sigprocmask (SIG_SETMASK, &omask, NULL);
+
                 if (display)
 		  bonobo_activation_setenv ("DISPLAY", display);
 		if (od_iorstr)
