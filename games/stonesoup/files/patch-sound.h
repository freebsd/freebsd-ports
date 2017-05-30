--- sound.h.orig	2017-05-30 15:27:57 UTC
+++ sound.h
@@ -19,14 +19,14 @@
 //
 // WARNING: Filenames passed to this command *are not validated in any way*.
 //
-//#define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 \"%s\" 2>/dev/null &"
+%%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/play -v .5 \"%s\" 2>/dev/null &"
 
 // Uncomment this to enable playing sounds that play sounds that pause the
 // gameplay until they finish.
 //
 // WARNING: This feature is not fully implemented yet!
 //
-//#define HOLD_SOUND_PLAY_COMMAND "/usr/bin/play -v .5 \"%s\" 2>/dev/null"
+%%SOUND%%#define HOLD_SOUND_PLAY_COMMAND "%%LOCALBASE%%/play -v .5 \"%s\" 2>/dev/null"
 
 
 // These are generic queues for playing sounds; they're intended for
