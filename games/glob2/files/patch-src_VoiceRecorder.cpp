--- ./src/VoiceRecorder.cpp.orig	2009-01-06 17:24:57.000000000 +0100
+++ ./src/VoiceRecorder.cpp	2009-03-01 18:33:04.000000000 +0100
@@ -36,7 +36,7 @@
 #define SPEEX_FRAME_SIZE 160
 
 #ifdef HAVE_PORTAUDIO
-	#include "portaudio.h"
+	#include <portaudio2/portaudio.h>
 #else
 	#ifdef WIN32
 		// Windows audio input include
