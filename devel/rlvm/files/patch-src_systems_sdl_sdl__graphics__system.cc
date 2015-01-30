--- src/systems/sdl/sdl_graphics_system.cc~
+++ src/systems/sdl/sdl_graphics_system.cc
@@ -32,7 +32,7 @@
 #include <SDL/SDL.h>
 #include <SDL/SDL_opengl.h>
 
-#if defined(__linux__)
+#if !defined(__APPLE__)
 #include <SDL/SDL_image.h>
 #endif
 
@@ -244,7 +244,7 @@ SDLGraphicsSystem::SDLGraphicsSystem(Sys
 
   SetWindowTitle();
 
-#if defined(__linux__)
+#if !defined(__APPLE__)
   // We only set the icon on linux because OSX will use the icns file
   // automatically and this doesn't look too awesome.
   SDL_Surface* icon = IMG_Load("/usr/share/icons/hicolor/48x48/apps/rlvm.png");
