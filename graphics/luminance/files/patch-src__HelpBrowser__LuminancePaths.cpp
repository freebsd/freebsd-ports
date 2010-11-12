--- ./src/HelpBrowser/LuminancePaths.cpp.orig	2009-12-05 19:28:52.000000000 +0300
+++ ./src/HelpBrowser/LuminancePaths.cpp	2010-11-12 14:20:53.460402688 +0300
@@ -35,7 +35,7 @@
 	hf = LocalizedDirPath(QApplication::applicationDirPath() + dirsep + "help" + dirsep );
 #else
 //	hf = LocalizedDirPath( PREFIX + dirsep + "share" + dirsep + "fontmatrix" + dirsep + "help" + dirsep );
-	hf = LocalizedDirPath( "/usr" + dirsep + "share" + dirsep + "luminance" + dirsep + "help" + dirsep );
+        hf = LocalizedDirPath( "%%HELPDIR%%/" );
 #endif
 	getThis()->LuminancePathsDB["HelpDir"] = hf;
 
