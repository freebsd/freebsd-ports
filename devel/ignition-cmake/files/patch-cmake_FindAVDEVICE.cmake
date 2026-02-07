--- cmake/FindAVDEVICE.cmake.orig	2023-04-24 07:29:47 UTC
+++ cmake/FindAVDEVICE.cmake
@@ -20,4 +20,5 @@ set(av_minor ${AVDEVICE_FIND_VERSION_MINOR})
 set(av_patch ${AVDEVICE_FIND_VERSION_PATCH})
 
 include(IgnPkgConfig)
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 ign_pkg_check_modules(AVDEVICE "libavdevice >= ${av_major}.${av_minor}.${av_patch}")
