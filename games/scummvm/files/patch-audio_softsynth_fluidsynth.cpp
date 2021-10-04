Fix build with FluidSynth >= 2.2.0

Obtained from:

https://github.com/NetBSD/pkgsrc/commit/25b35d66ba06339121f9ed19cc0a307a7b61dfc9

--- audio/softsynth/fluidsynth.cpp.orig	2020-09-13 21:05:37 UTC
+++ audio/softsynth/fluidsynth.cpp
@@ -144,11 +144,11 @@ static void *SoundFontMemLoader_open(const char *filen
 	return p;
 }
 
-static int SoundFontMemLoader_read(void *buf, int count, void *handle) {
+static int SoundFontMemLoader_read(void *buf, long long count, void *handle) {
 	return ((Common::SeekableReadStream *) handle)->read(buf, count) == (uint32)count ? FLUID_OK : FLUID_FAILED;
 }
 
-static int SoundFontMemLoader_seek(void *handle, long offset, int origin) {
+static int SoundFontMemLoader_seek(void *handle, long long offset, int origin) {
 	return ((Common::SeekableReadStream *) handle)->seek(offset, origin) ? FLUID_OK : FLUID_FAILED;
 }
 
@@ -157,7 +157,7 @@ static int SoundFontMemLoader_close(void *handle) {
 	return FLUID_OK;
 }
 
-static long SoundFontMemLoader_tell(void *handle) {
+static long long SoundFontMemLoader_tell(void *handle) {
 	return ((Common::SeekableReadStream *) handle)->pos();
 }
 #endif
