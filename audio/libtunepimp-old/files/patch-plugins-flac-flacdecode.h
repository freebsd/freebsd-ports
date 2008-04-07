--- plugins/flac/flacdecode.h.orig	2008-03-28 21:08:34.000000000 +0100
+++ plugins/flac/flacdecode.h	2008-03-28 21:08:49.000000000 +0100
@@ -27,7 +27,7 @@
 #ifndef __VORBIS_DECODE_H
 #define __VORBIS_DECODE_H
 
-#include <FLAC/file_decoder.h>
+#include <FLAC/stream_decoder.h>
 #include <string>
 #include "decode_plugin.h"
 #include "fileio.h"
