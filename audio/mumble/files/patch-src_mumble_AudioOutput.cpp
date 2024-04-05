--- src/mumble/AudioOutput.cpp.orig	2024-03-03 17:26:27 UTC
+++ src/mumble/AudioOutput.cpp
@@ -617,11 +617,11 @@ bool AudioOutput::mix(void *outbuff, unsigned int fram
 						// Mix down stereo to mono. TODO: stereo record support
 						// frame: for a stereo stream, the [LR] pair inside ...[LR]LRLRLR.... is a frame
 						for (unsigned int i = 0; i < frameCount; ++i) {
-							recbuff[i] += (pfBuffer[2 * i] / 2.0f + pfBuffer[2 * i + 1] / 2.0f) * volumeAdjustment;
+							recbuff[static_cast< int >(i)] += (pfBuffer[2 * i] / 2.0f + pfBuffer[2 * i + 1] / 2.0f) * volumeAdjustment;
 						}
 					} else {
 						for (unsigned int i = 0; i < frameCount; ++i) {
-							recbuff[i] += pfBuffer[i] * volumeAdjustment;
+							recbuff[static_cast< int >(i)] += pfBuffer[i] * volumeAdjustment;
 						}
 					}
 
