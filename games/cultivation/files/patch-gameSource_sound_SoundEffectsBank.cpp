--- gameSource/sound/SoundEffectsBank.cpp.orig	2007-08-09 15:45:15 UTC
+++ gameSource/sound/SoundEffectsBank.cpp
@@ -10,6 +10,7 @@
 
 #include "minorGems/util/random/StdRandomSource.h"
 
+#include <math.h>
 
 extern int globalSoundSampleRate;
 
