Find the okular headers when they are installed into a subdirectory of
${LOCALBASE}/include too (it currently follows x11/kdelibs4 and installs into
include/kde4).
--- OkularConfig.cmake.orig	2016-03-11 08:43:22 UTC
+++ OkularConfig.cmake
@@ -7,7 +7,7 @@ get_filename_component( _okularBaseDir  
 
 # find the full paths to the library and the includes:
 find_path(OKULAR_INCLUDE_DIR okular/core/document.h
-          HINTS ${_okularBaseDir}/include
+          HINTS ${_okularBaseDir}/include PATH_SUFFIXES kde4
           NO_DEFAULT_PATH)
 
 find_library(OKULAR_CORE_LIBRARY okularcore 
