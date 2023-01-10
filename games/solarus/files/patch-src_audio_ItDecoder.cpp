--- src/audio/ItDecoder.cpp.orig	2023-01-09 22:24:56 UTC
+++ src/audio/ItDecoder.cpp
@@ -17,7 +17,7 @@
 #include "solarus/audio/ItDecoder.h"
 #include "solarus/core/Debug.h"
 #include <stdafx.h>  // These two headers are with the libmodplug ones.
-#include <sndfile.h>
+#include <libmodplug/sndfile.h>
 
 namespace Solarus {
 
