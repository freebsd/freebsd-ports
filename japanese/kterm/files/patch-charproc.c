--- charproc.c.orig	2016-11-04 21:41:21 UTC
+++ charproc.c
@@ -103,8 +103,8 @@ extern jmp_buf VTend;
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
@@ -1974,6 +1974,12 @@ static void VTparse()
 			}
 			parsestate = groundtable;
 			break;
+
+                 case CASE_ECH:
+                        /* ECH */
+                        ClearRightN(screen, param[0] < 1 ? 1 : param[0]);
+                        parsestate = groundtable;
+                        break;
 
 		 case CASE_IL:
 			/* IL */
