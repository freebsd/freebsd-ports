Fix compiler error (missing include)

--- es-core/src/Sound.h.orig	2018-08-11 01:14:12 UTC
+++ es-core/src/Sound.h
@@ -5,6 +5,7 @@
 #include "SDL_audio.h"
 #include <map>
 #include <memory>
+#include <string>
 
 class ThemeData;
 
