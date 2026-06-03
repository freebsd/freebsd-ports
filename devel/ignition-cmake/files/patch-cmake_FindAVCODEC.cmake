-- Help cmake find avcodec from multimedia/ffmpeg4, which installs to %%LOCALBASE%%/ffmpeg4
--- cmake/FindAVCODEC.cmake.orig	2024-01-01 00:00:00 UTC
+++ cmake/FindAVCODEC.cmake
@@ -16,4 +16,5 @@
 ########################################
 # Find avcodec
 include(GzPkgConfig)
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 gz_pkg_check_modules_quiet(AVCODEC libavcodec)
