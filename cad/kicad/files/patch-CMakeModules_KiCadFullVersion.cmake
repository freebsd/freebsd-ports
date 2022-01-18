--- CMakeModules/KiCadFullVersion.cmake.orig	2022-01-17 23:51:27 UTC
+++ CMakeModules/KiCadFullVersion.cmake
@@ -27,10 +27,6 @@
 # repository), or the version from KiCadVersion.cmake. The user-provided
 # KICAD_VERSION_EXTRA is then appended to the base version string.
 
-# Use git to determine the version string if it's available.
-include( ${CMAKE_MODULE_PATH}/CreateGitVersionHeader.cmake )
-create_git_version_header( ${SRC_PATH} )
-
 # $KICAD_VERSION is set in KiCadVersion.cmake or by git (if it is available).
 set( KICAD_VERSION_FULL "${KICAD_VERSION}" )
 
