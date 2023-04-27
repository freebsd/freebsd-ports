--- cmake/FindAVCODEC.cmake.orig	2023-04-24 07:29:13 UTC
+++ cmake/FindAVCODEC.cmake
@@ -16,4 +16,5 @@
 ########################################
 # Find avcodec
 include(IgnPkgConfig)
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 ign_pkg_check_modules(AVCODEC libavcodec)
