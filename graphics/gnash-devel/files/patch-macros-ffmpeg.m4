--- macros/ffmpeg.m4.orig	2011-06-24 09:51:50.606673957 +0200
+++ macros/ffmpeg.m4	2011-06-24 09:52:10.371550401 +0200
@@ -184,9 +184,9 @@
 
     AC_MSG_CHECKING([ffmpeg version])
 
-    ffmpeg_major_version=`$EGREP "define LIBAVCODEC_VERSION_MAJOR " ${avcodec_h} | sed -e "s%[[^0-9]]%%g"`
-    ffmpeg_minor_version=`$EGREP "define LIBAVCODEC_VERSION_MINOR " ${avcodec_h} | sed -e "s%[[^0-9]]%%g"`
-    ffmpeg_micro_version=`$EGREP "define LIBAVCODEC_VERSION_MICRO " ${avcodec_h} | sed -e "s%[[^0-9]]%%g"`
+    ffmpeg_major_version=`$EGREP "define LIBAVCODEC_VERSION_MAJOR " ${ffmpeg_top_incl}/libavcodec/version.h | sed -e "s%[[^0-9]]%%g"`
+    ffmpeg_minor_version=`$EGREP "define LIBAVCODEC_VERSION_MINOR " ${ffmpeg_top_incl}/libavcodec/version.h | sed -e "s%[[^0-9]]%%g"`
+    ffmpeg_micro_version=`$EGREP "define LIBAVCODEC_VERSION_MICRO " ${ffmpeg_top_incl}/libavcodec/version.h | sed -e "s%[[^0-9]]%%g"`
 
     if test x"${ffmpeg_major_version}" != x ; then
 
