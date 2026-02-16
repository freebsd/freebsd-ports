- workaround for https://github.com/Yoshimi/yoshimi/issues/174

--- src/globals.h.orig	2026-02-14 16:53:10 UTC
+++ src/globals.h
@@ -123,7 +123,7 @@ using ushort = unsigned short;
 #define UNTITLED "No Title"
 
 #define DEFAULT_AUDIO jack_audio
-#define DEFAULT_MIDI alsa_midi
+#define DEFAULT_MIDI jack_midi
 
 #define FORCED_EXIT 16
 
