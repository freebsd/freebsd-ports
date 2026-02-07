--- src/main.c.orig	2003-07-11 17:11:56 UTC
+++ src/main.c
@@ -45,7 +45,7 @@
 #include "save.h"
 
 
-extern SDL_Joystick *sdl_joy;
+SDL_Joystick *sdl_joy;
 
 void exit_gngb(void)
 {
