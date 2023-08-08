--- cmake_modules/FindLIBAV.cmake.orig	2023-04-25 07:46:45 UTC
+++ cmake_modules/FindLIBAV.cmake
@@ -19,6 +19,8 @@
 #  BSD license.
 #
 
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
+
 include(FindPackageHandleStandardArgs)
 
 
