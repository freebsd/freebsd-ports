--- ./AppHdr.h.orig	2011-08-12 20:37:59.000000000 +0200
+++ ./AppHdr.h	2011-10-04 20:14:30.000000000 +0200
@@ -125,7 +125,7 @@
     //
     // WARNING: Filenames passed to this command *are not validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 \"%s\" 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 \"%s\" 2>/dev/null &"
 
     // For cases when the game will be played on terms that don't support the
     // curses "bold == lighter" 16 colour mode. -- bwr
