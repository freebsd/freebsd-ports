--- zpsfx.cpp.orig	2016-07-26 12:10:41 UTC
+++ zpsfx.cpp
@@ -16,19 +16,38 @@ Or use appropriate optimization options.
 the executable smaller. -DNDEBUG turns off run time checks.
 To convert a ZPAQ archive to a self extracting archive:
 
+On Windows:
+
   copy/b zpsfx.exe+zpsfx.tag+archive.zpaq archive.exe
 
+On FreeBSD(the choice of archive name is discretionary): 
+
+  cat zpsfx zpsfx.tag archive.zpaq > archive.sfx
+
 zpsfx.tag is a 13 byte file used to mark the start of the compressed data
 that is appended. Alternatively, zpaq with the "t" modifier will append
 the same tag ("a" appends).
 
+On Windows:
+
   copy zpsfx.exe archive.exe
   zpaq ta archive.exe files...
 
+On FreeBSD:
+
+  cp zpsfx archive.sfx
+  zpaq ta archive.sfx files...
+
 To extract:
 
+On Windows:
+
   archive.exe
 
+On FreeBSD:
+
+  archive.sfx
+
 The program reads itself and decompresses the appended archive.
 You must enter the .exe extension as shown. If the file is not in
 the current folder then you need to specify the path. The PATH environment
@@ -44,7 +63,11 @@ stored filename. SHA-1 checksums are not
 #include <stdio.h>
 #include <stdlib.h>
 #include <string>
+#ifdef unix
+#include <sys/stat.h>
+#else
 #include <windows.h>
+#endif
 
 // An error handler is required as shown in this example. libzpaq will
 // call it with an English language message in case of a fatal error.
@@ -96,7 +119,11 @@ struct Buf: public libzpaq::Writer {
 
 // Return '/' in Linux or '\' in Windows
 char slash() {
+#ifdef unix
+  return '/';
+#else
   return '\\';
+#endif
 }
 
 // Create directories as needed. For example if path="/tmp/foo/bar"
@@ -106,7 +133,11 @@ void makepath(std::string& path) {
   for (int i=0; i<path.size(); ++i) {
     if (path[i]=='\\' || path[i]=='/') {
       path[i]=0;
+#ifdef unix
+      int ok=!mkdir(path.c_str(), 0777);
+#else
       int ok=CreateDirectory(path.c_str(), 0);
+#endif
       path[i]=slash();
     }
   }
