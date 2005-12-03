--- src/sounddrv/soundsdl.c.orig	Sat Jan 12 21:35:58 2002
+++ src/sounddrv/soundsdl.c	Fri Feb 14 03:13:41 2003
@@ -26,7 +26,7 @@
 
 /* XXX: includes */
 
-#include <SDL/SDL_audio.h>
+#include <SDL_audio.h>
 #include <unistd.h>
 
 #include "vice.h"
