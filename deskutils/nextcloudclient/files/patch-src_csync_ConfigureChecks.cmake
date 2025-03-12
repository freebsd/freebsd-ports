--- src/csync/ConfigureChecks.cmake.orig	2025-03-06 09:00:02 UTC
+++ src/csync/ConfigureChecks.cmake
@@ -13,9 +13,6 @@ set(SOURCEDIR ${CMAKE_CURRENT_SOURCE_DIR})
 set(BINARYDIR ${CMAKE_CURRENT_BINARY_DIR})
 set(SOURCEDIR ${CMAKE_CURRENT_SOURCE_DIR})
 
-# HEADER FILES
-check_include_file(argp.h HAVE_ARGP_H)
-
 # FUNCTIONS
 if (NOT LINUX)
     # librt
