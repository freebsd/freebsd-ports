--- kodilib/src/tools/KFileTools.cpp.orig	2004-06-30 20:03:38.000000000 +0400
+++ kodilib/src/tools/KFileTools.cpp	2013-12-24 05:02:16.028538916 +0400
@@ -214,8 +214,8 @@
 // --------------------------------------------------------------------------------------------------------
 string kFileSuffix ( const string & path )
 {
-    unsigned int lastDotPos = path.rfind(".");
-    unsigned int lastSlashPos = path.rfind(kPathSep);
+    size_t lastDotPos = path.rfind(".");
+    size_t lastSlashPos = path.rfind(kPathSep);
 
     if (lastDotPos < path.size() - 1 && (lastDotPos > lastSlashPos || lastSlashPos == string::npos))
     {
@@ -228,7 +228,7 @@
 string kFileDirName ( const string & path )
 {
 	string native = kFileNativePath(path);
-    unsigned int lastSlashPos = native.rfind(kPathSep);
+    size_t lastSlashPos = native.rfind(kPathSep);
     if (lastSlashPos < native.size())
     {
         return native.substr(0, lastSlashPos+1);
@@ -241,7 +241,7 @@
 {
 	string native = kFileNativePath(path);
     string baseName = native;
-    unsigned int lastSlashPos = native.rfind(kPathSep);
+    size_t lastSlashPos = native.rfind(kPathSep);
     if (lastSlashPos < native.size() - 1) 
     {
         baseName = native.substr(lastSlashPos+1);
