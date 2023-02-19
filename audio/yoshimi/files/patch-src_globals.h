- workaround for https://github.com/Yoshimi/yoshimi/issues/174

--- src/globals.h.orig	2023-02-19 18:22:47 UTC
+++ src/globals.h
@@ -126,8 +126,8 @@ typedef unsigned int  uint;
 #define DEFAULT_NAME "Simple Sound"
 #define UNTITLED "No Title"
 
-#define DEFAULT_AUDIO alsa_audio
-#define DEFAULT_MIDI alsa_midi
+#define DEFAULT_AUDIO jack_audio
+#define DEFAULT_MIDI jack_midi
 
 #define FORCED_EXIT 16
 
