--- dlxsim/tcl/tclCmdAH.c.orig	Sun Sep 22 09:45:45 2002
+++ dlxsim/tcl/tclCmdAH.c	Sun Sep 22 10:02:26 2002
@@ -17,7 +17,7 @@
 
 #ifndef lint
 static char rcsid[] = "$Header: /sprite/src/lib/tcl/RCS/tclCmdAH.c,v 1.38 90/01/15 15:15:48 ouster Exp Locker: ouster $ SPRITE (Berkeley)";
-#endif not lint
+#endif
 
 #include <ctype.h>
 #include <errno.h>
@@ -413,7 +413,7 @@
 					 * id. */
     void (*oldHandler)();
     int handlerSet = 0;
-    union wait status;
+    int status;
     char *cmdName;
 
     /*
@@ -557,7 +557,7 @@
 	execSignalled = 0;
 	deadPid = wait3(&status, WNOHANG, (struct rusage *) 0);
 	if (deadPid == pid) {
-	    result = status.w_T.w_Retcode;
+	    result = WIFEXITED(status);
 	}
 
 	/*
