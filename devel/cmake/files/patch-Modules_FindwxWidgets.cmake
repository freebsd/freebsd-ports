--- Modules/FindwxWidgets.cmake.orig	2015-07-23 15:59:33.000000000 +0200
+++ Modules/FindwxWidgets.cmake	2015-08-10 20:04:36.068295000 +0200
@@ -741,7 +741,7 @@
     #-----------------------------------------------------------------
     # Support cross-compiling, only search in the target platform.
     find_program(wxWidgets_CONFIG_EXECUTABLE
-      NAMES wx-config wx-config-3.0 wx-config-2.9 wx-config-2.8
+      NAMES $ENV{WX_CONFIG} wx-config wx-config-3.0 wx-config-2.9 wx-config-2.8
       DOC "Location of wxWidgets library configuration provider binary (wx-config)."
       ONLY_CMAKE_FIND_ROOT_PATH
       )
