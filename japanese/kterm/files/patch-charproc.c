--- charproc.c.orig	Tue Jul  2 04:34:14 2002
+++ charproc.c	Tue Jul  2 04:34:29 2002
@@ -102,8 +102,8 @@
 extern XtAppContext app_con;
 extern Widget toplevel;
 extern void exit();
-extern char *malloc();
-extern char *realloc();
+extern void *malloc();
+extern void *realloc();
 extern fd_set Select_mask;
 extern fd_set X_mask;
 extern fd_set pty_mask;
@@ -1837,6 +1837,12 @@
 			parsestate = groundtable;
 			break;
 
+                 case CASE_ECH:
+                        /* ECH */
+                        ClearRightN(screen, param[0] < 1 ? 1 : param[0]);
+                        parsestate = groundtable;
+                        break;
+
 		 case CASE_IL:
 			/* IL */
 			if((row = param[0]) < 1)
