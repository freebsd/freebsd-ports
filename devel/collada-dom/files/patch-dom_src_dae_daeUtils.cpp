--- dom/src/dae/daeUtils.cpp.orig	2017-10-21 05:05:24 UTC
+++ dom/src/dae/daeUtils.cpp
@@ -18,7 +18,7 @@
 #endif
 
 #ifndef NO_BOOST
-#include <boost/filesystem/convenience.hpp>       // THIS WAS NOT COMMENTED.
+#include <boost/filesystem.hpp>       // THIS WAS NOT COMMENTED.
 #endif
 
 #include <cstdio> // for tmpnam
@@ -152,7 +152,7 @@ const string& cdom::getSystemTmpDir() {
 const string& cdom::getSystemTmpDir() {
 #ifdef WIN32
     static string tmpDir = string(getenv("TMP")) + getFileSeparator();
-#elif defined(__linux__) || defined(__linux)
+#elif defined(__linux__) || defined(__linux) || defined(__FreeBSD__)
     static string tmpDir = "/tmp/";
 #elif defined __APPLE_CC__
 static string tmpDir = string(getenv("TMPDIR"));
@@ -171,7 +171,7 @@ string cdom::getRandomFileName() {
     std::string tmp(tmpnam(&tmpbuffer[0]));
 #ifdef WIN32
     randomSegment = tmp.substr(tmp.find_last_of('\\')+1);
-#elif defined(__linux__) || defined(__linux)
+#elif defined(__linux__) || defined(__linux) || defined(__FreeBSD__)
     randomSegment = tmp.substr(tmp.find_last_of('/')+1);
 #elif defined __APPLE_CC__
 	randomSegment = tmp.substr(tmp.find_last_of('/')+1);
