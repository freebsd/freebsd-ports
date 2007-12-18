--- aycore/tgui.c.orig	2007-12-17 18:30:39.000000000 +0100
+++ aycore/tgui.c	2007-12-17 18:33:44.000000000 +0100
@@ -439,7 +439,7 @@
 
   /* register some C-functions as Tcl-Commands */
   Tcl_CreateCommand (interp, "tguiCmd",
-		     ay_tgui_tcmd,
+		     (Tcl_CmdProc *)ay_tgui_tcmd,
 		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
 
   /* register TP tag type */
