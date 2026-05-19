-- Help cmake find avutil from multimedia/ffmpeg4, which installs to %%LOCALBASE%%/ffmpeg4
--- cmake/FindAVUTIL.cmake.orig	2024-01-01 00:00:00 UTC
+++ cmake/FindAVUTIL.cmake
@@ -16,4 +16,5 @@
 ########################################
 # Find avutil
 include(GzPkgConfig)
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 gz_pkg_check_modules_quiet(AVUTIL libavutil)
