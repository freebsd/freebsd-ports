--- ./Modules/FindwxWindows.cmake.orig	2010-06-28 19:15:57.000000000 +0400
+++ ./Modules/FindwxWindows.cmake	2010-07-06 02:06:30.769844610 +0400
@@ -599,7 +599,8 @@
 
     # wx-config should be in your path anyhow, usually no need to set WXWIN or
     # search in ../wx or ../../wx
-    FIND_PROGRAM(CMAKE_WXWINDOWS_WXCONFIG_EXECUTABLE wx-config
+    FIND_PROGRAM(CMAKE_WXWINDOWS_WXCONFIG_EXECUTABLE NAMES $ENV{WX_CONFIG} wx-config
+      PATHS
       $ENV{WXWIN}
       $ENV{WXWIN}/bin
       ../wx/bin
