--- ./AppHdr.h.orig	2013-09-30 20:32:00.000000000 +0200
+++ ./AppHdr.h	2013-10-11 22:07:08.165888633 +0200
@@ -146,7 +146,7 @@
     //
     // WARNING: Filenames passed to this command *are not validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 \"%s\" 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 \"%s\" 2>/dev/null &"
 
     #include "libunix.h"
 
