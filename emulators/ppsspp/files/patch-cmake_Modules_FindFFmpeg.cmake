--- cmake/Modules/FindFFmpeg.cmake.orig	2024-02-04 13:08:02 UTC
+++ cmake/Modules/FindFFmpeg.cmake
@@ -56,9 +56,7 @@ function(find_ffmpeg LIBNAME)
 set(_FFmpeg_HEADER_swscale swscale)
 
 function(find_ffmpeg LIBNAME)
-  if(DEFINED ENV{FFMPEG_DIR})
-    set(FFMPEG_DIR $ENV{FFMPEG_DIR})
-  endif()
+  set(FFMPEG_DIR /usr/local/ffmpeg3)
 
   if(FFMPEG_DIR)
     list(APPEND INCLUDE_PATHS
@@ -79,17 +77,13 @@ function(find_ffmpeg LIBNAME)
       NO_CMAKE_FIND_ROOT_PATH
     )
   else()
-    list(APPEND INCLUDE_PATHS
-      /usr/local/include/ffmpeg
-      /usr/local/include/lib${LIBNAME}
-      /usr/include/ffmpeg
-      /usr/include/lib${LIBNAME}
-      /usr/include/ffmpeg/lib${LIBNAME}
+    list(SET INCLUDE_PATHS
+      /usr/local/ffmpeg3/include/ffmpeg
+      /usr/local/ffmpeg3/include/lib${LIBNAME}
     )
 
-    list(APPEND LIB_PATHS
-      /usr/local/lib
-      /usr/lib
+    list(SET LIB_PATHS
+      /usr/local/ffmpeg3/lib
     )
   endif()
 
