--- CMakeModules/FindGTA.cmake.orig	2017-05-19 16:06:36 UTC
+++ CMakeModules/FindGTA.cmake
@@ -8,17 +8,6 @@
 # correspond to the ./configure --prefix=$GTA_DIR
 # used in building libgta.
 
-INCLUDE(FindPkgConfig OPTIONAL)
-
-IF(PKG_CONFIG_FOUND)
-
-    INCLUDE(FindPkgConfig)
-
-    PKG_CHECK_MODULES(GTA gta)
-
-ENDIF(PKG_CONFIG_FOUND)
-
-IF(NOT GTA_FOUND)
     FIND_PATH(GTA_INCLUDE_DIRS gta/gta.hpp
         $ENV{GTA_DIR}/include
         $ENV{GTA_DIR}
@@ -53,5 +42,3 @@ IF(NOT GTA_FOUND)
     IF(GTA_LIBRARY AND GTA_INCLUDE_DIRS)
         SET(GTA_FOUND "YES")
     ENDIF(GTA_LIBRARY AND GTA_INCLUDE_DIRS)
-
-ENDIF(NOT GTA_FOUND)
\ No newline at end of file
