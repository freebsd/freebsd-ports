--- master/child.c.orig	Fri Dec 15 18:30:13 1989
+++ master/child.c	Fri Aug  8 12:38:17 2003
@@ -21,7 +21,11 @@
 sigchld ()
 {
 	register INV *inv;
+#ifdef __FreeBSD__
+	int status;
+#else
 	union    wait status;
+#endif
 	char     mbuf[SIZ];
 	int      pid;
 	int      exitstat;
@@ -31,7 +35,11 @@
 			kill (pid, 9);
 			exitstat = 1;
 		} else
+#ifdef __FreeBSD__
+		  exitstat = WEXITSTATUS(status);
+#else
 			exitstat = status.w_retcode;
+#endif
 
 		for (inv = invitations; inv; inv = inv->next)
 		    if (inv->pid == pid) /* does pid match? */
