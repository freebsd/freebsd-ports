--- src/stel_sdl.cpp.orig	Thu Jun 17 14:11:01 2004
+++ src/stel_sdl.cpp	Thu Jun 17 14:16:40 2004
@@ -60,9 +60,18 @@
     Screen = SDL_SetVideoMode(core->get_screen_W(), core->get_screen_H(), core->get_bppMode(), Vflags);
 	if(!Screen)
 	{
-		printf("sdl: Couldn't set %dx%d video mode: %s!",
+		printf("sdl: Couldn't set %dx%d video mode (%s), retrying with stencil size 0\n",
 		core->get_screen_W(), core->get_screen_H(), SDL_GetError());
-		exit(-1);
+
+		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE,0);
+		Screen = SDL_SetVideoMode(core->get_screen_W(), core->get_screen_H(), core->get_bppMode(), Vflags);
+
+		if(!Screen)
+		{
+			printf("sdl: Couldn't set %dx%d video mode: %s!\n",
+			core->get_screen_W(), core->get_screen_H(), SDL_GetError());
+			exit(-1);
+		}
 	}
 
 	// Disable key repeat
