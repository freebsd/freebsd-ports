--- Modules/FindwxWidgets.cmake.orig	2020-10-11 10:51:15 UTC
+++ Modules/FindwxWidgets.cmake
@@ -761,7 +761,7 @@ else()
     #-----------------------------------------------------------------
     # Support cross-compiling, only search in the target platform.
     find_program(wxWidgets_CONFIG_EXECUTABLE
-      NAMES $ENV{WX_CONFIG} wx-config wx-config-3.1 wx-config-3.0 wx-config-2.9 wx-config-2.8
+      NAMES $ENV{WX_CONFIG} wx-config wxgtk3u-3.1-config wxgtk3u-3.0-config wxgtk2u-2.8-config wx-config-3.1 wx-config-3.0 wx-config-2.9 wx-config-2.8
       DOC "Location of wxWidgets library configuration provider binary (wx-config)."
       ONLY_CMAKE_FIND_ROOT_PATH
       )
