--- dateeditor.C.orig	1996-02-10 04:17:35.000000000 +0100
+++ dateeditor.C	2003-04-28 18:14:32.000000000 +0200
@@ -113,7 +113,7 @@ int Cmd_HiliteLoop(ClientData, Tcl_Inter
     }
 
     int count;
-    char** strlist;
+    CONST84 char** strlist;
     if (Tcl_SplitList(tcl, argv[2], &count, &strlist) != TCL_OK) {
 	return TCL_ERROR;
     }
@@ -148,12 +148,12 @@ int Cmd_HiliteLoop(ClientData, Tcl_Inter
 	char buffer[20];
 	sprintf(buffer, "%d", list[i].date.EpochDays());
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
 
@@ -165,11 +165,11 @@ int Cmd_HiliteLoop(ClientData, Tcl_Inter
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
 
