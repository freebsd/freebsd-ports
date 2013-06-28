--- cmake/readline.cmake.orig	2013-06-28 21:04:29.807976388 +0200
+++ cmake/readline.cmake	2013-06-28 21:04:49.685326016 +0200
@@ -147,7 +147,7 @@
 
   FIND_LIBRARY(EDITLINE_LIBRARY
     NAMES
-    edit
+    readline
   )
   MARK_AS_ADVANCED(EDITLINE_INCLUDE_DIR EDITLINE_LIBRARY)
 
