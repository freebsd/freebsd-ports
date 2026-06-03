-- Help cmake find avformat from multimedia/ffmpeg4, which installs to %%LOCALBASE%%/ffmpeg4
--- cmake/FindAVFORMAT.cmake.orig	2024-01-01 00:00:00 UTC
+++ cmake/FindAVFORMAT.cmake
@@ -16,4 +16,5 @@
 ########################################
 # Find AV format
 include(GzPkgConfig)
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 gz_pkg_check_modules_quiet(AVFORMAT libavformat)
