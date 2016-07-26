--- base/src/registrar.cpp.orig	2003-09-16 17:34:54 UTC
+++ base/src/registrar.cpp
@@ -35,7 +35,7 @@ ________________________________________
 #include <stdlib.h>
 #include <unistd.h>
 #include <set>
-#include <wordexp.h>
+#include <glob.h>
 #endif // WIN32
 
 #include <stdio.h>
@@ -86,13 +86,13 @@ InitializeRegistry(Registry* registry, P
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
