--- Modules/FindwxWindows.cmake.orig	2012-11-06 21:41:36.000000000 +0200
+++ Modules/FindwxWindows.cmake	2012-11-27 22:39:17.000000000 +0200
@@ -598,7 +598,7 @@
 
     # wx-config should be in your path anyhow, usually no need to set WXWIN or
     # search in ../wx or ../../wx
-    find_program(CMAKE_WXWINDOWS_WXCONFIG_EXECUTABLE wx-config
+    find_program(CMAKE_WXWINDOWS_WXCONFIG_EXECUTABLE NAMES $ENV{WX_CONFIG} wx-config
       HINTS
         ENV WXWIN
         $ENV{WXWIN}/bin
