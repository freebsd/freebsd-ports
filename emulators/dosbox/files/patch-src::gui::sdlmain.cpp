--- src/gui/sdlmain.cpp.orig	Sun May 11 14:05:10 2003
+++ src/gui/sdlmain.cpp	Sun May 11 14:06:05 2003
@@ -39,9 +39,7 @@
 //#define DISABLE_JOYSTICK
 #define C_GFXTHREADED 1						//Enabled by default
 
-#if defined(MACOSX)
 extern char** environ;
-#endif
 
 struct SDL_Block {
 	volatile bool active;						//If this isn't set don't draw
