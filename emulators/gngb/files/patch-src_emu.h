--- src/emu.h.orig	2003-05-09 10:32:27 UTC
+++ src/emu.h
@@ -64,11 +64,11 @@ typedef struct {
   Sint32 pal[5][4];
 }GNGB_CONF;
 
-GNGB_CONF conf;
+extern GNGB_CONF conf;
 
-SDL_Joystick *sdl_joy;
+extern SDL_Joystick *sdl_joy;
 
-Uint16 key[SDLK_LAST];
+extern Uint16 key[SDLK_LAST];
 extern Sint16 *joy_axis;
 extern Uint8 *joy_but;
 
