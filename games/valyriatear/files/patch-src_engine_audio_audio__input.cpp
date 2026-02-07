--- src/engine/audio/audio_input.cpp.orig	2019-12-02 08:48:39 UTC
+++ src/engine/audio/audio_input.cpp
@@ -27,6 +27,7 @@
 #include "utils/utils_common.h"
 
 #include <cstring>
+#include <SDL_endian.h>
 
 namespace vt_audio
 {
