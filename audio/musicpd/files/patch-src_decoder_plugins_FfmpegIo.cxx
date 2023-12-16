https://github.com/MusicPlayerDaemon/MPD/issues/1898

--- src/decoder/plugins/FfmpegIo.cxx.orig	2023-10-08 08:11:05 UTC
+++ src/decoder/plugins/FfmpegIo.cxx
@@ -25,6 +25,7 @@ extern "C" {
 #include "input/InputStream.hxx"
 
 extern "C" {
+#include <libavutil/error.h>
 #include <libavutil/mem.h>
 }
 
