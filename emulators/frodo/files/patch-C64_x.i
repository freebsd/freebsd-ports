--- C64_x.i.orig	Wed Aug  6 20:56:25 1997
+++ C64_x.i	Mon Apr 26 21:50:36 1999
@@ -100,7 +100,7 @@
 	gui = 0;
 #else
 	// try to start up Tk gui.
-	gui = new CmdPipe("wish", "TkGui.tcl");
+	gui = new CmdPipe("wish8.4", "TkGui.tcl");
 	if (gui) {
 		if (gui->fail) {
 			delete gui; gui = 0;
