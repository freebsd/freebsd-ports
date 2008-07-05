--- cmake/FindQt4.cmake.orig	2008-07-05 05:20:44.000000000 +0000
+++ cmake/FindQt4.cmake	2008-07-05 05:20:52.000000000 +0000
@@ -859,7 +859,7 @@
     )
 
   FIND_PROGRAM(QT_LRELEASE_EXECUTABLE
-    NAMES lrelease
+    NAMES lrelease-qt4
     PATHS ${QT_BINARY_DIR}
     NO_DEFAULT_PATH
     )
