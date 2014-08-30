--- ./AppHdr.h.orig	2014-08-28 05:28:56.000000000 +0200
+++ ./AppHdr.h	2014-08-29 18:32:12.007217932 +0200
@@ -146,7 +146,7 @@
     //
     // WARNING: Filenames passed to this command *are not validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 \"%s\" 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 \"%s\" 2>/dev/null &"
 
     #include "libunix.h"
 
