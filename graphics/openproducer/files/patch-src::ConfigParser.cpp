--- src/ConfigParser.cpp.orig	Tue Jul 27 18:02:19 2004
+++ src/ConfigParser.cpp	Wed Jan 26 11:03:38 2005
@@ -1686,7 +1686,7 @@
 
 bool CameraConfig::parseFile( const std::string &file )
 {
-    fileName.clear();
+    fileName.erase();
 
     fileName = findFile(file);
 
