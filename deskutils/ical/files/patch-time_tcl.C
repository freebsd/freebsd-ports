--- time_tcl.C.orig	1994-05-20 03:22:05 UTC
+++ time_tcl.C
@@ -135,7 +135,7 @@ int Cmd_Date(ClientData, Tcl_Interp* tcl, int argc, ch
 		TCL_Return(tcl, "0");
 
 	    // Set variables
-	    sprintf(buffer, "%d", result.EpochDays());
+	    sprintf(buffer, "%ld", result.EpochDays());
 	    if (Tcl_SetVar(tcl, argv[3], buffer, 0) == NULL)
 		TCL_Error(tcl, "could not set <date> result");
 
