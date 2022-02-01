--- cmake/modules/FindOCIO.cmake.orig	2021-08-24 07:56:28 UTC
+++ cmake/modules/FindOCIO.cmake
@@ -33,11 +33,11 @@ find_path(OCIO_INCLUDE_DIR OpenColorIO.h
         /usr/local/include
         /sw/include
         /opt/local/include
-        PATH_SUFFIXES OpenColorIO
+        PATH_SUFFIXES OpenColorIOv1
         DOC "The directory where OpenColorIO/OpenColorIO.h resides"
 )
 
-find_library(OCIO_LIBRARIES OpenColorIO
+find_library(OCIO_LIBRARIES OpenColorIOv1
         PATHS
         ${OCIO_LIBRARY_PATH}
         ${OCIO_PATH}/lib/
