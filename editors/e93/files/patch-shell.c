--- ./shell.c.orig	Mon May 31 19:37:29 2004
+++ ./shell.c	Wed Dec 20 14:24:36 2006
@@ -935,7 +935,7 @@
 	return(TCL_ERROR);
 }
 
-static void TraceCheckAbortProc(ClientData theClientData,Tcl_Interp *theInterpreter,int theLevel,char *theCommand,Tcl_CmdProc *theProc,ClientData cmdClientData,int argc,const char *argv[])
+static void TraceCheckAbortProc(ClientData theClientData,Tcl_Interp *theInterpreter,int theLevel,char *theCommand,Tcl_CmdProc *theProc,ClientData cmdClientData,int argc,char *argv[])
 // This is a small trick on Tcl. We tell it we want to trace, but really, we want
 // to check to see if the user is trying to abort the execution of a script.
 // So, every time we are called, we check to see if the user is aborting, and
