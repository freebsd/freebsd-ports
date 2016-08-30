--- base/src/utility.cpp.orig	2004-02-10 18:20:22 UTC
+++ base/src/utility.cpp
@@ -33,6 +33,7 @@ ________________________________________
 #include <time.h>
 #include <ctype.h>
 #include <stdio.h>
+#include <cstdlib>
 
 #include <string>
 #include <vector>
@@ -56,7 +57,7 @@ using namespace std;
 #include "win32impl.h"
 #include "browser.h"
 #include <unistd.h>
-#include <wordexp.h>
+#include <glob.h>
 #define MKDIR(z) mkdir(z, 0755)
 #define _stat stat
 #ifndef _S_IFDIR
@@ -825,13 +826,13 @@ SplitPath(const string& path)
 
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
