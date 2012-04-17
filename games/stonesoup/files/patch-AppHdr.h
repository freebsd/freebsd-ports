--- ./AppHdr.h.orig	2012-04-10 21:47:14.000000000 +0200
+++ ./AppHdr.h	2012-04-14 18:50:22.264960252 +0200
@@ -126,7 +126,7 @@
     //
     // WARNING: Filenames passed to this command *are not validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 \"%s\" 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 \"%s\" 2>/dev/null &"
 
     // For cases when the game will be played on terms that don't support the
     // curses "bold == lighter" 16 colour mode. -- bwr
