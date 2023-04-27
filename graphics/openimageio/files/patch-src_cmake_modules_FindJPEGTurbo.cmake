--- src/cmake/modules/FindJPEGTurbo.cmake.orig	2023-01-30 22:36:11 UTC
+++ src/cmake/modules/FindJPEGTurbo.cmake
@@ -9,7 +9,8 @@ find_path(JPEG_INCLUDE_DIR turbojpeg.h
 include (FindPackageHandleStandardArgs)
 
 find_path(JPEG_INCLUDE_DIR turbojpeg.h
-          HINTS /usr/local/opt/jpeg-turbo/include
+          HINTS /usr/local
+                %%LOCALBASE%%
           PATH_SUFFIXES include)
 set(JPEG_NAMES ${JPEG_NAMES} jpeg libjpeg turbojpeg libturbojpeg)
 
