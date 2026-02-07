Fix detection of OpenJPEG 2.x if 1.5 is also installed.

--- cmake/modules/FindOpenJPEG.cmake.orig	2023-09-14 09:35:53 UTC
+++ cmake/modules/FindOpenJPEG.cmake
@@ -45,7 +45,7 @@ include(FindPackageHandleStandardArgs)
 
 # No hints in this case because the library versions semantically
 # the module folder, and it's also capitalized, so let CMake handle it.
-find_package(OPENJPEG QUIET NO_MODULE NAMES OpenJPEG)
+find_package(OPENJPEG 2 QUIET NO_MODULE NAMES OpenJPEG)
 mark_as_advanced(OPENJPEG_DIR)
 
 if(OPENJPEG_FOUND)
