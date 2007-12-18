--- contrib/tree.c.orig	2007-09-21 13:30:37.000000000 +0200
+++ contrib/tree.c	2007-12-17 19:03:54.000000000 +0100
@@ -898,19 +898,19 @@
   */
 
   /* create new Tcl commands */
-  Tcl_CreateCommand(interp, "treeGetString", ay_tree_gettreetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "treeGetString", (Tcl_CmdProc *)ay_tree_gettreetcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "treeSelect", ay_tree_selecttcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "treeSelect", (Tcl_CmdProc *)ay_tree_selecttcmd,
+		    NULL, NULL);
 
   /*
   Tcl_CreateCommand(interp, "CreateDndObject", aytree_CreateDndObject_tcmd,
 		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
   */
 
-  Tcl_CreateCommand(interp, "treeDnd", ay_tree_dndtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "treeDnd", (Tcl_CmdProc *)ay_tree_dndtcmd,
+		    NULL, NULL);
 
 
 
