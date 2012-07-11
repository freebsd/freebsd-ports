--- Modules/FindDCMTK.cmake.orig	2012-07-11 12:01:05.000000000 +0200
+++ Modules/FindDCMTK.cmake	2012-07-11 12:01:51.000000000 +0200
@@ -56,6 +56,7 @@
     ijg12
     ijg16
     ijg8
+    oflog
     ofstd)
 
   find_library(DCMTK_${lib}_LIBRARY
