--- ./Modules/FindInotify.cmake.orig	2012-04-18 16:08:32.799038053 +0200
+++ ./Modules/FindInotify.cmake	2012-04-18 16:18:43.588979805 +0200
@@ -1,11 +1,20 @@
-set(INOTIFY_H "NOTFOUND")
-find_file(INOTIFY_H
-  "sys/inotify.h"
-  PATHS ENV INCLUDE
+find_path(INOTIFY_INCLUDE_DIR
+  NAMES sys/inotify.h
+  PATHS
+    /usr/local/include
+    /usr/include
 )
 
-if (INOTIFY_H)
+find_library(INOTIFY_LIBRARY
+  NAMES inotify
+  PATHS
+    /usr/local/lib
+    /usr/lib
+    /lib
+)
+
+if(INOTIFY_INCLUDE_DIR AND INOTIFY_LIBRARY)
   set(INOTIFY_FOUND TRUE)
-else()
+else(INOTIFY_INCLUDE_DIR AND INOTIFY_LIBRARY)
   set(INOTIFY_FOUND FALSE)
-endif()
+endif(INOTIFY_INCLUDE_DIR AND INOTIFY_LIBRARY)
