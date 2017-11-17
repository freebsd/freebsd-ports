Work around "call to 'abs' is ambiguous" error in src/map.cc:936

--- src/map.cc.orig	2017-11-08 15:08:21.784137000 +0100
+++ src/map.cc	2017-11-08 15:24:09.192718000 +0100
@@ -24,6 +24,8 @@
 #include "editMode.h"
 #include "game.h"
 
+#include <cstdlib>
+
 #include <SDL2/SDL_endian.h>
 #include <SDL2/SDL_image.h>
 #include <zlib.h>
