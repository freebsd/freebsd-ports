--- ./cmake/modules/FindNeon.cmake.orig	2007-05-12 07:09:24.000000000 -0400
+++ ./cmake/modules/FindNeon.cmake	2009-05-20 06:44:50.000000000 -0400
@@ -1,28 +1,10 @@
-INCLUDE(UsePkgConfig)
-PKGCONFIG(neon _NeonIncDir _NeonLinkDir _NeonLinkFlags _NeonCflags)
-
-FIND_PATH(NEON_INCLUDE_DIR ne_request.h
-    ${_NeonIncDir}
-    /usr/include/neon
-    /usr/local/include/neon
-)
+FIND_PATH(NEON_INCLUDE_DIR NAMES ne_request.h PATH_SUFFIXES neon)
 
-FIND_LIBRARY(NEON_LIBRARIES neon
-    ${_NeonLinkDir}
-    /usr/lib
-    /usr/local/lib
-)
+FIND_LIBRARY(NEON_LIBRARY NAMES neon)
 
-IF (NEON_INCLUDE_DIR AND NEON_LIBRARIES)
-    SET(NEON_FOUND TRUE)
-ENDIF (NEON_INCLUDE_DIR AND NEON_LIBRARIES)
+INCLUDE(FindPackageHandleStandardArgs)
+FIND_PACKAGE_HANDLE_STANDARD_ARGS(NEON DEFAULT_MSG NEON_LIBRARY NEON_INCLUDE_DIR)
 
-IF (NEON_FOUND)
-    IF (NOT Neon_FIND_QUIETLY)
-	MESSAGE(STATUS "Found Neon: ${NEON_LIBRARIES}")
-    ENDIF (NOT Neon_FIND_QUIETLY)
-ELSE (NEON_FOUND)
-    IF (Neon_FIND_REQUIRED)
-	MESSAGE(FATAL_ERROR "Could not find Neon")
-    ENDIF (Neon_FIND_REQUIRED)
-ENDIF (NEON_FOUND)
+IF(NEON_FOUND)
+  SET(NEON_LIBRARIES ${NEON_LIBRARY})
+ENDIF(NEON_FOUND)
