--- Config.cpp.orig	Tue Mar  5 16:15:53 2002
+++ Config.cpp	Tue Mar  5 16:16:50 2002
@@ -16,7 +16,7 @@
 	flipFPS = MainWindow::F30;
 	loadFrames = 100;
 	
-	mpegExec	= "/usr/bin/mpeg_encode";
+	mpegExec	= "%%LOCALBASE%%/bin/mpeg_encode";
 	mpegPattern	= "IBBPBBPBBPBB";
 	mpegPSearch	= 0;
 	mpegBSearch = 1;
