--- ./Modules/FindwxWidgets.cmake.orig	2010-06-28 19:15:57.000000000 +0400
+++ ./Modules/FindwxWidgets.cmake	2010-07-06 02:06:02.277945209 +0400
@@ -689,7 +689,7 @@
     # UNIX: Start actual work.
     #-----------------------------------------------------------------
     # Support cross-compiling, only search in the target platform.
-    FIND_PROGRAM(wxWidgets_CONFIG_EXECUTABLE wx-config
+    FIND_PROGRAM(wxWidgets_CONFIG_EXECUTABLE NAMES $ENV{WX_CONFIG} wx-config
       ONLY_CMAKE_FIND_ROOT_PATH
       )
 
