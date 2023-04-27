--- cmake/FindAVUTIL.cmake.orig	2023-04-24 07:30:38 UTC
+++ cmake/FindAVUTIL.cmake
@@ -16,4 +16,5 @@
 ########################################
 # Find avutil
 include(IgnPkgConfig)
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 ign_pkg_check_modules(AVUTIL libavutil)
