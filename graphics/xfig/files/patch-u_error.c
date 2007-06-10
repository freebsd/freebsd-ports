--- u_error.c.orig	Tue Jul 26 09:40:00 2005
+++ u_error.c
@@ -59,7 +59,7 @@
     emergency_quit(True);
 }
 
-void X_error_handler(Display *d, XErrorEvent *err_ev)
+int X_error_handler(Display *d, XErrorEvent *err_ev)
 {
     char	    err_msg[MAXERRMSGLEN];
     char	    ernum[10];
@@ -75,6 +75,7 @@
     XGetErrorDatabaseText(tool_d, "XRequest", ernum, "<Unknown>", err_msg, MAXERRMSGLEN);
     (void) fprintf(stderr, "Request code: %s\n",err_msg);
     emergency_quit(True);
+    return 0;
 }
 
 void emergency_quit(Boolean abortflag)
