--- ./cmake/modules/FindFFmpeg.cmake.orig	2012-09-05 18:05:36.000000000 +0000
+++ ./cmake/modules/FindFFmpeg.cmake	2013-03-24 22:35:28.751290553 +0000
@@ -39,16 +39,16 @@
 		/opt/include
 		/usr/freeware/include
 		NO_DEFAULT_PATH
-		PATH_SUFFIXES ffmpeg
+		PATH_SUFFIXES ffmpeg${FFMPEG_SUFFIX}
 		DOC "Location of FFMPEG Headers"
 	)
 	FIND_PATH(FFMPEG_${varname}_INCLUDE_DIRS lib${shortname}/${headername}
-		PATH_SUFFIXES ffmpeg
+		PATH_SUFFIXES ffmpeg${FFMPEG_SUFFIX}
 		DOC "Location of FFMPEG Headers"
 	)
 
     FIND_LIBRARY(FFMPEG_${varname}_LIBRARIES
-        NAMES ${shortname}
+        NAMES ${shortname}${FFMPEG_SUFFIX}
         PATHS
         ${FFMPEG_ROOT}/lib
         $ENV{FFMPEG_DIR}/lib
@@ -63,11 +63,12 @@
         /opt/csw/lib
         /opt/lib
         /usr/freeware/lib64
+        PATH_SUFFIXES ffmpeg${FFMPEG_SUFFIX}
 		NO_DEFAULT_PATH
         DOC "Location of FFMPEG Libraries"
     )
     FIND_LIBRARY(FFMPEG_${varname}_LIBRARIES
-        NAMES ${shortname}
+        NAMES ${shortname}${FFMPEG_SUFFIX}
         DOC "Location of FFMPEG Libraries"
     )
 
@@ -77,6 +78,10 @@
 
 ENDMACRO(FFMPEG_FIND)
 
+if (NOT DEFINED FFMPEG_SUFFIX)
+    set(FFMPEG_SUFFIX 1)
+endif ()
+
 SET(FFMPEG_ROOT "$ENV{FFMPEG_DIR}" CACHE PATH "Location of FFMPEG")
 
 # find stdint.h
