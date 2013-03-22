--- ./libstreamanalyzer/cmake/FindFFmpeg.cmake.orig	2013-03-01 07:07:31.562142000 +0000
+++ ./libstreamanalyzer/cmake/FindFFmpeg.cmake	2013-03-06 00:32:09.269367542 +0000
@@ -71,13 +71,15 @@
       ${PC_LIB${_component}_INCLUDEDIR}
       ${PC_LIB${_component}_INCLUDE_DIRS}
     PATH_SUFFIXES
-      ffmpeg
+      ffmpeg${FFMPEG_SUFFIX}
   )
 
   find_library(${_component}_LIBRARIES NAMES ${_library}
-      HINTS
+    HINTS
       ${PC_LIB${_component}_LIBDIR}
       ${PC_LIB${_component}_LIBRARY_DIRS}
+    PATH_SUFFIXES
+      ffmpeg${FFMPEG_SUFFIX}
   )
 
   set(${_component}_DEFINITIONS  ${PC_${_component}_CFLAGS_OTHER} CACHE STRING "The ${_component} CFLAGS.")
@@ -97,13 +99,18 @@
 # Check for cached results. If there are skip the costly part.
 if (NOT FFMPEG_LIBRARIES)
 
+  # Look for ffmpeg1 by default. Use empty suffix for ffmpeg-0.7
+  if (NOT FFMPEG_SUFFIX)
+    set(FFMPEG_SUFFIX 1)
+  endif ()
+
   # Check for all possible component.
-  find_component(AVCODEC  libavcodec  avcodec  libavcodec/avcodec.h)
-  find_component(AVFORMAT libavformat avformat libavformat/avformat.h)
-  find_component(AVDEVICE libavdevice avdevice libavdevice/avdevice.h)
-  find_component(AVUTIL   libavutil   avutil   libavutil/avutil.h)
-  find_component(SWSCALE  libswscale  swscale  libswscale/swscale.h)
-  find_component(POSTPROC libpostproc postproc libpostproc/postprocess.h)
+  find_component(AVCODEC  libavcodec${FFMPEG_SUFFIX}  avcodec${FFMPEG_SUFFIX}  libavcodec/avcodec.h)
+  find_component(AVFORMAT libavformat${FFMPEG_SUFFIX} avformat${FFMPEG_SUFFIX} libavformat/avformat.h)
+  find_component(AVDEVICE libavdevice${FFMPEG_SUFFIX} avdevice${FFMPEG_SUFFIX} libavdevice/avdevice.h)
+  find_component(AVUTIL   libavutil${FFMPEG_SUFFIX}   avutil${FFMPEG_SUFFIX}   libavutil/avutil.h)
+  find_component(SWSCALE  libswscale${FFMPEG_SUFFIX}  swscale${FFMPEG_SUFFIX}  libswscale/swscale.h)
+  find_component(POSTPROC libpostproc${FFMPEG_SUFFIX} postproc${FFMPEG_SUFFIX} libpostproc/postprocess.h)
 
   # Check if the required components were found and add their stuff to the FFMPEG_* vars.
   foreach (_component ${FFmpeg_FIND_COMPONENTS})
