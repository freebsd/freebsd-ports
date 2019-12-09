--- CMakeModules/FindGTA.cmake.orig	2014-01-19 17:46:13.693927259 +0400
+++ CMakeModules/FindGTA.cmake	2014-01-19 18:38:17.868997891 +0400
@@ -8,16 +8,6 @@
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
-ELSE(PKG_CONFIG_FOUND)
-
 FIND_PATH(GTA_INCLUDE_DIRS gta/gta.hpp
     $ENV{GTA_DIR}/include
     $ENV{GTA_DIR}
@@ -52,5 +42,3 @@
 IF(GTA_LIBRARIES AND GTA_INCLUDE_DIRS)
     SET(GTA_FOUND "YES")
 ENDIF(GTA_LIBRARIES AND GTA_INCLUDE_DIRS)
-
-ENDIF(PKG_CONFIG_FOUND)
