--- src/mpeg_encode.c.orig	2009-11-16 07:55:52.000000000 +0100
+++ src/mpeg_encode.c	2011-02-08 16:18:47.640994869 +0100
@@ -141,7 +141,7 @@
 /* -------------------------------------------------------- */
 #ifdef AMIDE_FFMPEG_SUPPORT
 
-#include <ffmpeg/libavcodec/avcodec.h>
+#include <libavcodec/avcodec.h>
 
 
 typedef struct {
