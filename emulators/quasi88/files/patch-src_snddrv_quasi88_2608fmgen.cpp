--- src/snddrv/quasi88/2608fmgen.cpp.orig	2011-05-26 15:42:50 UTC
+++ src/snddrv/quasi88/2608fmgen.cpp
@@ -92,7 +92,7 @@ static void *fmgen2608_start(int sndindex, int clock, 
 
 	if (info->opna->Init(clock,
 						 Machine->sample_rate ? Machine->sample_rate :44100,
-						 NULL)) {
+						 false)) {
 		if (sound2_adpcm) {
 			uint8* adpcmbuf = info->opna->GetADPCMBuffer();
 			if (adpcmbuf) {
