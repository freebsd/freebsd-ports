--- base/src/registrar.cpp.orig	Sat Mar 15 10:01:46 2003
+++ base/src/registrar.cpp	Mon Aug 18 18:54:16 2003
@@ -28,7 +28,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <set>
-#include <wordexp.h>
+#include <glob.h>
 #endif // WIN32
 
 #include <stdio.h>
@@ -79,13 +79,13 @@
         dir = *di++;
 
 #ifndef WIN32
-        wordexp_t result;
-        if (wordexp(dir.c_str(), &result, 0) ==0){
+        glob_t result;
+        if (glob(dir.c_str(), 0, NULL, &result) ==0){
              //cerr << "Expanded " << dir << " in ";
-             dir = result.we_wordv[0];
+             dir = result.gl_pathv[0];
              //cerr << dir << endl;
         }
-        wordfree(&result);
+        globfree(&result);
 
 #if 0
         if (dir[0] == '~') {
