--- plugins/mfio.c.orig	2007-12-17 19:15:06.000000000 +0100
+++ plugins/mfio.c	2007-12-17 19:17:03.000000000 +0100
@@ -3530,12 +3530,12 @@
 
   /* register some C-functions as Tcl-Commands */
   Tcl_CreateCommand (interp, "ay_mfio_import",
-		     ay_mfio_importscenetcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+		     (Tcl_CmdProc *)ay_mfio_importscenetcmd,
+		     NULL, NULL);
 
   Tcl_CreateCommand (interp, "ay_mfio_export",
-		     ay_mfio_exportscenetcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+		     (Tcl_CmdProc *)ay_mfio_exportscenetcmd,
+		     NULL, NULL);
 
   /* source mfio.tcl, it contains Tcl-code for menu entries */
   if((Tcl_EvalFile(interp, "mfio.tcl")) != TCL_OK)
