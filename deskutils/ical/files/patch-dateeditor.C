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
