--- src/csync/ConfigureChecks.cmake.orig	2021-09-03 09:40:46 UTC
+++ src/csync/ConfigureChecks.cmake
@@ -14,9 +14,6 @@ set(SYSCONFDIR ${SYSCONF_INSTALL_DIR})
 set(BINARYDIR ${CMAKE_CURRENT_BINARY_DIR})
 set(SOURCEDIR ${CMAKE_CURRENT_SOURCE_DIR})
 
-# HEADER FILES
-check_include_file(argp.h HAVE_ARGP_H)
-
 # FUNCTIONS
 if (NOT LINUX)
     # librt
