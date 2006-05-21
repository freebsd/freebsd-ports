--- ./client/snd_loc.h.orig	Wed Jan 11 10:51:56 2006
+++ ./client/snd_loc.h	Sat May 20 13:44:43 2006
@@ -22,7 +22,7 @@
 #ifdef OGG_SUPPORT
 #if defined __unix__
 #include <vorbis/vorbisfile.h> // Knightmare added- vorbis support
-#include <AL/altypes.h>
+#include <AL/al.h>
 #else
 #include "include/vorbisfile.h" // Knightmare added- vorbis support
 #include "include/altypes.h"
