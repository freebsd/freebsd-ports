-- Help cmake find avdevice from multimedia/ffmpeg4, which installs to %%LOCALBASE%%/ffmpeg4
--- cmake/FindAVDEVICE.cmake.orig	2024-01-01 00:00:00 UTC
+++ cmake/FindAVDEVICE.cmake
@@ -20,4 +20,5 @@ set(av_minor ${AVDEVICE_FIND_VERSION_MINOR})
 set(av_patch ${AVDEVICE_FIND_VERSION_PATCH})
 
 include(GzPkgConfig)
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 gz_pkg_check_modules_quiet(AVDEVICE "libavdevice >= ${av_major}.${av_minor}.${av_patch}")
