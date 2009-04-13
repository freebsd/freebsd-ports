--- src/lib/Options.cpp	2003-02-04 22:34:51.000000000 -0500
+++ src/lib/Options.cpp	2009-04-13 01:59:11.000000000 -0400
@@ -24,7 +24,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
-#include <iostream.h>
+#include <iostream>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
 
 #include "Debug.hpp"
 #include "Options.hpp"
@@ -90,7 +93,19 @@
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
