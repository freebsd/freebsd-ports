--- src/common.h.orig	Fri Aug 22 06:07:09 2003
+++ src/common.h	Thu Sep  4 05:31:40 2003
@@ -22,13 +22,13 @@
 // APPLE path is different (thanks Minami)
 #ifdef __APPLE__
 #include <GLUT/glut.h>
-#include "SDL/SDL.h"
-#include "SDL/SDL_thread.h"
+#include "SDL.h"
+#include "SDL_thread.h"
 #ifdef HAVE_SDL_MIXER
-#include "SDL/SDL_mixer.h"
+#include "SDL_mixer.h"
 #endif
 #ifdef HAVE_SDL_NET
-#include "SDL/SDL_net.h"
+#include "SDL_net.h"
 #endif
 #endif
 #ifndef __APPLE__
@@ -36,13 +36,13 @@
 #include <GL/glut.h>
 #else
 #include <GL/glut.h>
-#include "SDL/SDL.h"
-#include "SDL/SDL_thread.h"
+#include "SDL.h"
+#include "SDL_thread.h"
 #ifdef HAVE_SDL_MIXER
-#include "SDL/SDL_mixer.h"
+#include "SDL_mixer.h"
 #endif
 #ifdef HAVE_SDL_NET
-#include "SDL/SDL_net.h"
+#include "SDL_net.h"
 #endif
 #endif
 #endif // __APPLE__
