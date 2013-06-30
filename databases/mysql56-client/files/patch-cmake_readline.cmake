--- cmake/readline.cmake.orig	2013-06-30 10:45:55.000000000 +0200
+++ cmake/readline.cmake	2013-06-30 10:47:08.000000000 +0200
@@ -147,7 +147,7 @@
 
   FIND_LIBRARY(EDITLINE_LIBRARY
     NAMES
-    edit
+    readline
   )
   MARK_AS_ADVANCED(EDITLINE_INCLUDE_DIR EDITLINE_LIBRARY)
 
