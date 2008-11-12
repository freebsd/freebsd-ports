--- config.m4.orig	2006-09-30 02:14:15.000000000 +0800
+++ config.m4	2008-07-28 15:53:18.099676966 +0800
@@ -6,7 +6,11 @@
 
   AC_MSG_CHECKING(for ffmpeg headers)
   for i in $PHP_FFMPEG /usr/local /usr ; do
-    if test -f $i/include/ffmpeg/avcodec.h; then
+    if test -f $i/include/libavcodec/avcodec.h; then
+      FFMPEG_DIR=$i
+      FFMPEG_INCDIR="$i/include/libavcodec $i/include/libavformat"
+      break
+    elif test -f $i/include/ffmpeg/avcodec.h; then
       FFMPEG_DIR=$i
       FFMPEG_INCDIR=$i/include/ffmpeg
       break
@@ -45,7 +49,10 @@
 
   PHP_ADD_LIBRARY_WITH_PATH(avcodec, $FFMPEG_LIBDIR, FFMPEG_SHARED_LIBADD)
   PHP_ADD_LIBRARY_WITH_PATH(avformat, $FFMPEG_LIBDIR, FFMPEG_SHARED_LIBADD)
-  PHP_ADD_INCLUDE($FFMPEG_INCDIR)
+
+  for i in $FFMPEG_INCDIR; do
+    PHP_ADD_INCLUDE($i)
+  done
 
   PHP_NEW_EXTENSION(ffmpeg, ffmpeg-php.c ffmpeg_movie.c ffmpeg_frame.c ffmpeg_animated_gif.c, $ext_shared,, \\$(GDLIB_CFLAGS))
   PHP_SUBST(FFMPEG_SHARED_LIBADD)
