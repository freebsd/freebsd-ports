
$FreeBSD$

--- renderers/audio/sdl/sdl_audio_renderer.h.orig	Fri Nov  3 21:41:37 2000
+++ renderers/audio/sdl/sdl_audio_renderer.h	Sun Feb  4 22:55:34 2001
@@ -34,7 +34,7 @@
 
 #include "libxmps/libxmps.h"
 
-#include <SDL/SDL.h>
+#include <SDL.h>
 #include <string.h>
 
 #ifdef HAVE_CONFIG_H
