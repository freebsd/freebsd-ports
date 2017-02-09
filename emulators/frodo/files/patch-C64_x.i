--- C64_x.i.orig	2002-01-02 21:16:45 UTC
+++ C64_x.i
@@ -100,7 +100,7 @@ void C64::c64_ctor1(void)
 	gui = 0;
 #else
 	// try to start up Tk gui.
-	gui = new CmdPipe("wish", "TkGui.tcl");
+	gui = new CmdPipe("wish8.4", "TkGui.tcl");
 	if (gui) {
 		if (gui->fail) {
 			delete gui; gui = 0;
