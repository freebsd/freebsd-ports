--- ./AppHdr.h.orig	2009-10-06 20:44:04.000000000 +0200
+++ ./AppHdr.h	2009-10-15 18:40:29.000000000 +0200
@@ -151,7 +151,7 @@
     //          setuid or setgid. Filenames passed to this command *are not
     //          validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 %s 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 %s 2>/dev/null &"
 
     // For cases when the game will be played on terms that don't support the
     // curses "bold == lighter" 16 colour mode. -- bwr
