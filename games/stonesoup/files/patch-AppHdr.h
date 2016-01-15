--- AppHdr.h.orig	2015-10-31 04:31:32 UTC
+++ AppHdr.h
@@ -152,7 +152,7 @@ static inline double pow(int x, double y
     //
     // WARNING: Filenames passed to this command *are not validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 \"%s\" 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 \"%s\" 2>/dev/null &"
 
     #include "libunix.h"
 
