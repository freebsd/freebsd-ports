--- src/common.h.orig	Sun Jun 13 11:17:16 2004
+++ src/common.h	Sun Jun 13 11:17:43 2004
@@ -22,13 +22,13 @@
 // APPLE path is different (thanks Minami)
 #ifdef __APPLE__
 #include <GLUT/glut.h>
-#include "SDL/SDL.h"
-#include "SDL/SDL_thread.h"
+#include "SDL11/SDL.h"
+#include "SDL11/SDL_thread.h"
 #ifdef HAVE_SDL_MIXER
-#include "SDL/SDL_mixer.h"
+#include "SDL11/SDL_mixer.h"
 #endif
 #ifdef HAVE_SDL_NET
-#include "SDL/SDL_net.h"
+#include "SDL11/SDL_net.h"
 #endif
 #endif
 #ifndef __APPLE__
@@ -36,13 +36,13 @@
 #include <GL/glut.h>
 #else
 #include <GL/glut.h>
-#include "SDL/SDL.h"
-#include "SDL/SDL_thread.h"
+#include "SDL11/SDL.h"
+#include "SDL11/SDL_thread.h"
 #ifdef HAVE_SDL_MIXER
-#include "SDL/SDL_mixer.h"
+#include "SDL11/SDL_mixer.h"
 #endif
 #ifdef HAVE_SDL_NET
-#include "SDL/SDL_net.h"
+#include "SDL11/SDL_net.h"
 #endif
 #endif
 #endif // __APPLE__
