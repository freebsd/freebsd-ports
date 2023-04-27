--- cmake/FindAVFORMAT.cmake.orig	2023-04-24 07:30:02 UTC
+++ cmake/FindAVFORMAT.cmake
@@ -16,4 +16,5 @@
 ########################################
 # Find AV format
 include(IgnPkgConfig)
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 ign_pkg_check_modules(AVFORMAT libavformat)
