--- gameSource/sound/SoundPlayer.h.orig	2015-05-30 19:01:03 UTC
+++ gameSource/sound/SoundPlayer.h
@@ -52,9 +52,7 @@
 #include "SoundFilter.h"
 #include "PlayableSound.h"
 
-#include "minorGems/sound/portaudio/pa_common/portaudio.h"
-#include "minorGems/sound/portaudio/pablio/pablio.h"
-
+#include <portaudio.h>
 
 #include "minorGems/util/SimpleVector.h"
 
