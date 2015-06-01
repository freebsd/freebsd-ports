--- AppHdr.h.orig	2015-03-23 01:49:21 UTC
+++ AppHdr.h
@@ -147,7 +147,7 @@ static inline double pow(int x, double y
     //
     // WARNING: Filenames passed to this command *are not validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 \"%s\" 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 \"%s\" 2>/dev/null &"
 
     #include "libunix.h"
 
