--- CMake/FindFFmpeg.cmake.orig	2013-03-24 17:28:47.675682879 +0100
+++ CMake/FindFFmpeg.cmake	2013-03-24 17:29:04.915681918 +0100
@@ -70,16 +70,16 @@
 
   find_path(${_component}_INCLUDE_DIRS ${_header}
     HINTS
-      ${PC_LIB${_component}_INCLUDEDIR}
-      ${PC_LIB${_component}_INCLUDE_DIRS}
+      ${PC_${_component}_INCLUDEDIR}
+      ${PC_${_component}_INCLUDE_DIRS}
     PATH_SUFFIXES
       ffmpeg
   )
 
   find_library(${_component}_LIBRARIES NAMES ${_library}
       HINTS
-      ${PC_LIB${_component}_LIBDIR}
-      ${PC_LIB${_component}_LIBRARY_DIRS}
+      ${PC_${_component}_LIBDIR}
+      ${PC_${_component}_LIBRARY_DIRS}
   )
 
   set(${_component}_DEFINITIONS  ${PC_${_component}_CFLAGS_OTHER} CACHE STRING "The ${_component} CFLAGS.")
@@ -94,13 +94,13 @@
 if (NOT FFMPEG_LIBRARIES)
 
   # Check for all possible component.
-  find_component(AVCODEC  libavcodec  avcodec  libavcodec/avcodec.h)
-  find_component(AVFORMAT libavformat avformat libavformat/avformat.h)
-  find_component(AVDEVICE libavdevice avdevice libavdevice/avdevice.h)
-  find_component(AVUTIL   libavutil   avutil   libavutil/avutil.h)
-  find_component(SWSCALE  libswscale  swscale  libswscale/swscale.h)
-  find_component(POSTPROC libpostproc postproc libpostproc/postprocess.h)
-  find_component(SWRESAMPLE libswresample swresample libswresample/swresample.h)
+  find_component(AVCODEC  libavcodec1  avcodec1  libavcodec/avcodec.h)
+  find_component(AVFORMAT libavformat1 avformat1 libavformat/avformat.h)
+  find_component(AVDEVICE libavdevice1 avdevice1 libavdevice/avdevice.h)
+  find_component(AVUTIL   libavutil1   avutil1   libavutil/avutil.h)
+  find_component(SWSCALE  libswscale1  swscale1  libswscale/swscale.h)
+  find_component(POSTPROC libpostproc1 postproc1 libpostproc/postprocess.h)
+  find_component(SWRESAMPLE libswresample1 swresample1 libswresample/swresample.h)
 
   # Check if the required components were found and add their stuff to the FFMPEG_* vars.
   foreach (_component ${FFmpeg_FIND_COMPONENTS})
