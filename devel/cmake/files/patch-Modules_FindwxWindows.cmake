--- Modules/FindwxWindows.cmake.orig	2017-05-31 14:00:09 UTC
+++ Modules/FindwxWindows.cmake
@@ -617,7 +617,7 @@ else()
 
     # wx-config should be in your path anyhow, usually no need to set WXWIN or
     # search in ../wx or ../../wx
-    find_program(CMAKE_WXWINDOWS_WXCONFIG_EXECUTABLE wx-config
+    find_program(CMAKE_WXWINDOWS_WXCONFIG_EXECUTABLE NAMES $ENV{WX_CONFIG} wx-config
       HINTS
         ENV WXWIN
         $ENV{WXWIN}/bin
