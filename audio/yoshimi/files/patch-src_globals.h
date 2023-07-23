- workaround for https://github.com/Yoshimi/yoshimi/issues/174

--- src/globals.h.orig	2023-05-29 08:38:23 UTC
+++ src/globals.h
@@ -117,7 +117,7 @@ typedef unsigned int  uint;
 #define UNTITLED "No Title"
 
 #define DEFAULT_AUDIO jack_audio
-#define DEFAULT_MIDI alsa_midi
+#define DEFAULT_MIDI jack_midi
 
 #define FORCED_EXIT 16
 
