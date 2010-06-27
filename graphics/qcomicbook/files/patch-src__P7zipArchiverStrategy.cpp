--- src/P7zipArchiverStrategy.cpp.orig	2010-06-13 09:48:03.000000000 -0300
+++ src/P7zipArchiverStrategy.cpp	2010-06-13 09:48:10.000000000 -0300
@@ -28,6 +28,7 @@
 void P7zipArchiverStrategy::configure()
 {
     addExtension(".7z");
+    addExtension(".cb7");
     setExecutables("7z", "7zr");
 
     if (which("7z") != QString::null)
