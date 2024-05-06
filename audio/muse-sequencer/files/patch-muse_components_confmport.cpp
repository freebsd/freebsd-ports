Fix build with ninja >= 1.12.0

https://github.com/muse-sequencer/muse/pull/1277

--- muse/components/confmport.cpp.orig	2023-09-24 15:12:36 UTC
+++ muse/components/confmport.cpp
@@ -45,7 +45,6 @@
 #include "midiport.h"
 #include "mididev.h"
 #include "midisyncimpl.h"
-#include "midifilterimpl.h"
 #include "ctrlcombo.h"
 #include "minstrument.h"
 #include "synth.h"
