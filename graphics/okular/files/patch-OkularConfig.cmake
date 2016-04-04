--- OkularConfig.cmake.orig	2016-03-11 08:43:22 UTC
+++ OkularConfig.cmake
@@ -7,7 +7,7 @@ get_filename_component( _okularBaseDir  
 
 # find the full paths to the library and the includes:
 find_path(OKULAR_INCLUDE_DIR okular/core/document.h
-          HINTS ${_okularBaseDir}/include
+          HINTS ${_okularBaseDir}/include PATH_SUFFIXES kde4
           NO_DEFAULT_PATH)
 
 find_library(OKULAR_CORE_LIBRARY okularcore 
