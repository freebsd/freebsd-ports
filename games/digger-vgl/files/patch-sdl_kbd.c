
$FreeBSD$

--- sdl_kbd.c	2001/09/12 21:53:57	1.1
+++ sdl_kbd.c	2001/09/12 21:54:03
@@ -1,3 +1,15 @@
+/*
+ * ---------------------------------------------------------------------------
+ * "THE BEER-WARE LICENSE" (Revision 42, (c) Poul-Henning Kamp): Maxim
+ * Sobolev <sobomax@altavista.net> wrote this file. As long as you retain
+ * this  notice you can  do whatever you  want with this stuff. If we meet
+ * some day, and you think this stuff is worth it, you can buy me a beer in
+ * return.
+ * 
+ * Maxim Sobolev
+ * --------------------------------------------------------------------------- 
+ */
+
 #include <SDL.h>
 
 #include "def.h"
@@ -14,8 +26,12 @@
 		if(klen == KBLEN) /* Buffer is full, drop some pieces */
 			memcpy(kbuffer, kbuffer + 1, --klen);
 		kbuffer[klen++] = event->key.keysym.sym;
-	}
 
+		/* ALT + Enter handling (fullscreen/windowed operation) */
+		if((event->key.keysym.sym == SDLK_RETURN || event->key.keysym.sym == SDLK_KP_ENTER) &&
+		    ((event->key.keysym.mod & KMOD_ALT) != 0))
+			switchmode();
+	}
 	if(event->type == SDL_QUIT)
 		exit(0);
 
@@ -28,7 +44,6 @@
 	
 	SDL_PumpEvents();
 	keys = SDL_GetKeyState(NULL);
-	
 	if (keys[key] == SDL_PRESSED )
 		return(TRUE);
 	else
