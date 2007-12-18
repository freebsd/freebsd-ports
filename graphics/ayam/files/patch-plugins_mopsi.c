--- plugins/mopsi.c.orig	2007-09-21 13:30:38.000000000 +0200
+++ plugins/mopsi.c	2007-12-17 19:50:09.000000000 +0100
@@ -2130,8 +2130,8 @@
   entry = Tcl_CreateHashEntry(&mopsiht, "ICurve", &new_item);
   Tcl_SetHashValue(entry, &(mopsi_icurve));
 
-  Tcl_CreateCommand(interp, "importMops", mopsi_tcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "importMops", (Tcl_CmdProc *)mopsi_tcmd,
+		    NULL, NULL);
 
   /* source mopsi.tcl, it contains vital Tcl-code */
   if((Tcl_EvalFile(interp, "mopsi.tcl")) != TCL_OK)
