--- ./src/subsim.cpp.orig	2007-06-11 11:16:23.000000000 -0400
+++ ./src/subsim.cpp	2014-08-11 09:56:15.000000000 -0400
@@ -31,6 +31,7 @@
 #else
 #include "oglext/OglExt.h"
 #endif
+#include <unistd.h>
 #include <glu.h>
 #include <SDL.h>
 #include <SDL_net.h>
