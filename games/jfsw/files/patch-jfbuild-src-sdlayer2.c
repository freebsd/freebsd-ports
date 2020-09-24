Fix include for FreeBSD

--- jfbuild/src/sdlayer2.c.orig	2020-09-22 22:08:35 UTC
+++ jfbuild/src/sdlayer2.c
@@ -22,7 +22,7 @@
 # define _GNU_SOURCE 1
 #endif
 
-#if defined __APPLE__
+#if defined __APPLE__ || __FreeBSD__
 # include <SDL2/SDL.h>
 #else
 # include "SDL.h"
