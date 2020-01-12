--- dateeditor.C.orig	1996-02-10 03:17:35 UTC
+++ dateeditor.C
@@ -146,14 +146,14 @@ int Cmd_HiliteLoop(ClientData, Tcl_Interp* tcl, int ar
 	if (!contains(hlist, hilite)) hilite = "always";
 
 	char buffer[20];
-	sprintf(buffer, "%d", list[i].date.EpochDays());
+	sprintf(buffer, "%ld", list[i].date.EpochDays());
 	if (Tcl_SetVar(tcl, dvar, buffer, 0) == NULL) {
-	    free((char*) strlist);
+	    Tcl_Free((char*) strlist);
 	    TCL_Error(tcl, "could not set loop variable");
 	}
 
 	if (Tcl_SetVar(tcl, hvar, (char*)hilite, 0) == NULL) {
-	    free((char*) strlist);
+	    Tcl_Free((char*) strlist);
 	    TCL_Error(tcl, "could not set loop variable");
 	}
 
@@ -165,11 +165,11 @@ int Cmd_HiliteLoop(ClientData, Tcl_Interp* tcl, int ar
 	if (result == TCL_BREAK) break;
 
 	// Error of some sort
-	free((char*) strlist);
+	Tcl_Free((char*) strlist);
 	return result;
     }
 
-    free((char*) strlist);
+    Tcl_Free((char*) strlist);
     TCL_Return(tcl, "");
 }
 
