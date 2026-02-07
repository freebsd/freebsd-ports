--- cmake/modules/FindOpenImageIO.cmake.orig	2019-08-31 15:49:01 UTC
+++ cmake/modules/FindOpenImageIO.cmake
@@ -42,6 +42,7 @@ include (FindPackageHandleStandardArgs)
 find_path (OPENIMAGEIO_INCLUDE_DIR NAMES OpenImageIO/imageio.h)
 
 find_library (OPENIMAGEIO_LIBRARY NAMES OpenImageIO)
+find_library (OPENIMAGEIOUTIL_LIBRARY NAMES OpenImageIO_Util)
 
 find_program (OPENIMAGEIO_OIIOTOOL NAMES oiiotool)
 find_program (OPENIMAGEIO_IDIFF NAMES idiff)
@@ -57,7 +58,7 @@ find_package_handle_standard_args (OPENIMAGEIO DEFAULT
 # Set the output variables.
 if (OPENIMAGEIO_FOUND)
     set (OPENIMAGEIO_INCLUDE_DIRS ${OPENIMAGEIO_INCLUDE_DIR})
-    set (OPENIMAGEIO_LIBRARIES ${OPENIMAGEIO_LIBRARY})
+    set (OPENIMAGEIO_LIBRARIES ${OPENIMAGEIO_LIBRARY} ${OPENIMAGEIOUTIL_LIBRARY})
 else ()
     set (OPENIMAGEIO_INCLUDE_DIRS)
     set (OPENIMAGEIO_LIBRARIES)
