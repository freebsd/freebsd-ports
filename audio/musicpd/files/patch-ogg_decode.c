--- src/ogg_decode.c.orig	Tue Sep 30 13:46:36 2003
+++ src/ogg_decode.c	Tue Sep 30 13:46:55 2003
@@ -28,6 +28,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <vorbis/vorbisfile.h>
+#include <sys/time.h>
 
 int ogg_decode(Buffer * cb, AudioFormat * af, DecoderControl * dc)
 {
