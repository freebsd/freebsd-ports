--- cmake/FindSWSCALE.cmake.orig	2023-04-25 18:35:25 UTC
+++ cmake/FindSWSCALE.cmake
@@ -16,4 +16,5 @@
 ########################################
 # Find libswscale format
 include(IgnPkgConfig)
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 ign_pkg_check_modules(SWSCALE libswscale)
