--- src/lib/Options.cpp.orig	Tue Nov 26 19:56:54 2002
+++ src/lib/Options.cpp	Tue Nov 26 19:59:02 2002
@@ -25,6 +25,9 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <iostream.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
 
 #include "Debug.hpp"
 #include "Options.hpp"
@@ -86,7 +89,19 @@
   char fullpath[OPTIONS_PATH_SIZE];
   snprintf(fullpath, OPTIONS_PATH_SIZE, "%s/%s", dir, OPTIONS_FILE_NAME);
 
-  ifstream in(fullpath, ios::nocreate);
+  // We only want to try to open the file if it already exists.
+  // ios::nocreate seems to have disappeared, so we'll use stat instead.
+
+  struct stat b;
+
+  if (-1 == stat(fullpath, &b))
+  {
+    LOG("could not open " << fullpath << endl);
+    return 1;
+  }
+
+  ifstream in(fullpath);
+
   if (! in) {
     LOG("could not open " << fullpath << endl);
     return 1;
