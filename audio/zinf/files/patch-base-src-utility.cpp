--- base/src/utility.cpp.orig	Sun May 11 15:45:31 2003
+++ base/src/utility.cpp	Mon Aug 18 18:57:01 2003
@@ -52,7 +52,7 @@
 #include "win32impl.h"
 #include "browser.h"
 #include <unistd.h>
-#include <wordexp.h>
+#include <glob.h>
 #define MKDIR(z) mkdir(z, 0755)
 #define _stat stat
 #ifndef _S_IFDIR
@@ -764,13 +764,13 @@
 
         if (subpath.size()) {
 #ifndef WIN32
-            wordexp_t result;
-            if (wordexp(subpath.c_str(), &result, 0) ==0){
+            glob_t result;
+            if (glob(subpath.c_str(), 0, NULL, &result) ==0){
                 //cerr << "Expanded " << dir << " in ";
-                subpath = result.we_wordv[0];
+                subpath = result.gl_pathv[0];
                 //cerr << dir << endl;
             }
-            wordfree(&result);
+            globfree(&result);
 #endif
 
             dirs.push_back(subpath);
