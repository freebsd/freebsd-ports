--- ./AppHdr.h.orig	2011-04-26 15:08:47.000000000 +0200
+++ ./AppHdr.h	2011-06-02 19:51:41.000000000 +0200
@@ -135,7 +135,7 @@
     //
     // WARNING: Filenames passed to this command *are not validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 \"%s\" 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 \"%s\" 2>/dev/null &"
 
     // For cases when the game will be played on terms that don't support the
     // curses "bold == lighter" 16 colour mode. -- bwr
