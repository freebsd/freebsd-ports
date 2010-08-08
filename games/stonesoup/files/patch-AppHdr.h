--- ./AppHdr.h.orig	2010-07-24 05:31:45.000000000 +0200
+++ ./AppHdr.h	2010-08-05 09:25:27.000000000 +0200
@@ -161,7 +161,7 @@
     //          setuid or setgid. Filenames passed to this command *are not
     //          validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 %s 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 %s 2>/dev/null &"
 
     // For cases when the game will be played on terms that don't support the
     // curses "bold == lighter" 16 colour mode. -- bwr
