
$FreeBSD$

--- src/video/x11/SDL_x11events.c	2001/01/27 17:49:30	1.1
+++ src/video/x11/SDL_x11events.c	2001/01/27 17:49:54
@@ -35,7 +35,9 @@
 #ifdef __SVR4
 #include <X11/Sunkeysym.h>
 #endif
+#include <sys/types.h>
 #include <sys/time.h>
+#include <unistd.h>
 
 #include "SDL.h"
 #include "SDL_syswm.h"
