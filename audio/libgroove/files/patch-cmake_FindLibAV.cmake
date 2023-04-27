--- cmake/FindLibAV.cmake.orig	2023-04-25 13:56:57 UTC
+++ cmake/FindLibAV.cmake
@@ -22,6 +22,8 @@
 # AVUTIL_INCLUDE_DIRS
 # AVUTIL_LIBRARIES
 
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/include;%%LOCALBASE%%/ffmpeg4/libexec")
+
 find_path(AVFILTER_INCLUDE_DIRS NAMES libavfilter/avfilter.h)
 find_library(AVFILTER_LIBRARIES NAMES avfilter)
 if(AVFILTER_LIBRARIES AND AVFILTER_INCLUDE_DIRS)
