--- Modules/FindwxWidgets.cmake.orig	2013-10-14 16:39:11.995705456 +0300
+++ Modules/FindwxWidgets.cmake	2013-10-14 16:39:31.315704621 +0300
@@ -702,7 +702,7 @@
     # UNIX: Start actual work.
     #-----------------------------------------------------------------
     # Support cross-compiling, only search in the target platform.
-    find_program(wxWidgets_CONFIG_EXECUTABLE wx-config
+    find_program(wxWidgets_CONFIG_EXECUTABLE NAMES $ENV{WX_CONFIG} wx-config
       DOC "Location of wxWidgets library configuration provider binary (wx-config)."
       ONLY_CMAKE_FIND_ROOT_PATH
       )
