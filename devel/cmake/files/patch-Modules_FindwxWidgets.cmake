--- Modules/FindwxWidgets.cmake.orig	2017-05-31 14:00:09 UTC
+++ Modules/FindwxWidgets.cmake
@@ -747,7 +747,7 @@ else()
     #-----------------------------------------------------------------
     # Support cross-compiling, only search in the target platform.
     find_program(wxWidgets_CONFIG_EXECUTABLE
-      NAMES wx-config wx-config-3.1 wx-config-3.0 wx-config-2.9 wx-config-2.8
+      NAMES $ENV{WX_CONFIG} wx-config-3.1 wx-config wx-config-3.0 wx-config-2.9 wx-config-2.8
       DOC "Location of wxWidgets library configuration provider binary (wx-config)."
       ONLY_CMAKE_FIND_ROOT_PATH
       )
