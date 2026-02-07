--- dom/src/dae/daeUtils.cpp.orig	2025-10-29 04:16:09 UTC
+++ dom/src/dae/daeUtils.cpp
@@ -152,7 +152,7 @@ const string& cdom::getSystemTmpDir() {
 const string& cdom::getSystemTmpDir() {
 #ifdef WIN32
     static string tmpDir = string(getenv("TMP")) + getFileSeparator();
-#elif defined(__linux__) || defined(__linux) || defined(__GLIBC__)
+#elif defined(__linux__) || defined(__linux) || defined(__GLIBC__) || defined(__FreeBSD__)
     static string tmpDir = "/tmp/";
 #elif defined __APPLE_CC__
 static string tmpDir = string(getenv("TMPDIR"));
@@ -171,7 +171,7 @@ string cdom::getRandomFileName() {
     std::string tmp(tmpnam(&tmpbuffer[0]));
 #ifdef WIN32
     randomSegment = tmp.substr(tmp.find_last_of('\\')+1);
-#elif defined(__linux__) || defined(__linux) || defined(__GLIBC__)
+#elif defined(__linux__) || defined(__linux) || defined(__GLIBC__) || defined(__FreeBSD__)
     randomSegment = tmp.substr(tmp.find_last_of('/')+1);
 #elif defined __APPLE_CC__
 	randomSegment = tmp.substr(tmp.find_last_of('/')+1);
