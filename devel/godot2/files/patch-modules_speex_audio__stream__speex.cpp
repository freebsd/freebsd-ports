--- modules/speex/audio_stream_speex.cpp.orig	2017-12-28 01:20:49 UTC
+++ modules/speex/audio_stream_speex.cpp
@@ -29,7 +29,7 @@
 #include "audio_stream_speex.h"
 
 #include "os/os.h"
-#include "os_support.h"
+#include "thirdparty/speex/os_support.h"
 #define READ_CHUNK 1024
 
 static _FORCE_INLINE_ uint16_t le_short(uint16_t s) {
