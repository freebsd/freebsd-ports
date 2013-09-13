--- src/audio/sound_error.hpp.orig	2013-07-09 01:03:45.000000000 +0200
+++ src/audio/sound_error.hpp	2013-09-13 17:09:14.252645154 +0200
@@ -18,6 +18,7 @@
 #define HEADER_SUPERTUX_AUDIO_SOUND_ERROR_HPP
 
 #include <stdexcept>
+#include <string>
 
 class SoundError : public std::exception
 {
