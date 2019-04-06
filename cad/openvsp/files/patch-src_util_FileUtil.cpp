--- src/util/FileUtil.cpp.orig	2019-03-28 20:30:27 UTC
+++ src/util/FileUtil.cpp
@@ -19,7 +19,9 @@
 #include <pwd.h>
 #endif
 
+#include <libgen.h>
 
+
 vector< string > ScanFolder( const char* dir_path )
 {
     vector< string > file_vec;
@@ -107,9 +109,18 @@ bail:
 
 string PathToExe()
 {
+
     int bufsize = 255;
     char *path = NULL;
     bool done = false;
+
+    char temp[PATH_MAX];
+    char exepath[PATH_MAX];
+
+    ::snprintf(temp, sizeof(temp),"/proc/curproc/file");
+    ::realpath(temp, exepath);
+
+    return dirname(exepath);
 
 // Pre-loop initialization.
 #ifdef WIN32
