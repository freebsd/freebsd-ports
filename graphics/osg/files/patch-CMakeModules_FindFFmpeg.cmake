--- CMakeModules/FindFFmpeg.cmake.orig	2023-04-24 09:16:25 UTC
+++ CMakeModules/FindFFmpeg.cmake
@@ -21,6 +21,7 @@
 #                                                       (in new version case, use by ffmpeg header) 
 #and ${FFMPEG_libname_INCLUDE_DIRS/libname}             (in new version case, use by osg plugin code)
 
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
 
 # Macro to find header and lib directories
 # example: FFMPEG_FIND(AVFORMAT avformat avformat.h)
