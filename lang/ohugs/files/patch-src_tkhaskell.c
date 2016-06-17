--- src/tkhaskell.c.orig	2001-01-28 06:02:45 UTC
+++ src/tkhaskell.c
@@ -160,17 +160,17 @@ static Int c_primInitTcl () { 
     Tcl_SetVar(interp, "tcl_interactive", "0", TCL_GLOBAL_ONLY);
 
     if (Tcl_Init(interp) == TCL_ERROR) {
-	fprintf(stderr, "%s\n", interp->result);
+	fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 	return(0);
     }
 
     if (Tk_Init(interp) == TCL_ERROR) {
-	fprintf(stderr, "%s\n", interp->result);
+	fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 	return FALSE;
     }
 #if O_TIX
     if (Tix_Init(interp) == TCL_ERROR) {
-	fprintf(stderr, "%s\n", interp->result);
+	fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 	return FALSE;
     }
 #endif
@@ -242,17 +242,17 @@ static String executeTcl (cmd) 
 String cmd; {
    char errmsg[200];
    if (Tcl_Eval(interp,cmd) != TCL_OK) {
-       fprintf(stderr, "###Tk/Tcl: %s\n", interp->result);
+       fprintf(stderr, "###Tk/Tcl: %s\n", Tcl_GetStringResult(interp));
        strcpy(errmsg,"###internalError {");
-       strcat (errmsg,interp -> result);
+       strcat (errmsg, Tcl_GetStringResult(interp));
        strcat (errmsg, " }");
        if (Tcl_Eval(interp,errmsg) != TCL_OK){
-         fprintf(stderr, "###%s\n", interp->result);
+         fprintf(stderr, "###%s\n", Tcl_GetStringResult(interp));
          exit(1);
          return ("");
        }
    }
-   return (interp -> result);
+   return (Tcl_GetStringResult(interp));
 } 
 
 
