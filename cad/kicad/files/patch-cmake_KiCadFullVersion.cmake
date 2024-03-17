--- cmake/KiCadFullVersion.cmake.orig	2023-04-13 20:27:39 UTC
+++ cmake/KiCadFullVersion.cmake
@@ -27,10 +27,6 @@
 # repository), or the version from KiCadVersion.cmake. The user-provided
 # KICAD_VERSION_EXTRA is then appended to the base version string.
 
-# Use git to determine the version string if it's available.
-include( ${KICAD_CMAKE_MODULE_PATH}/CreateGitVersionHeader.cmake )
-create_git_version_header( ${SRC_PATH} )
-
 # $KICAD_VERSION is set in KiCadVersion.cmake or by git (if it is available).
 set( KICAD_VERSION_FULL "${KICAD_VERSION}" )
 
