--- src/sdl_mixer.cpp.orig	Mon Jan 26 09:11:21 2004
+++ src/sdl_mixer.cpp	Mon Jan 26 09:11:31 2004
@@ -40,9 +40,9 @@
 //..............................................................................
 #include "powermanga.hpp"
 #ifdef UTILISE_SEAL
-#include <SDL/SDL.h>
-#include <SDL/SDL_thread.h>
-#include <SDL/SDL_mixer.h>
+#include <SDL.h>
+#include <SDL_thread.h>
+#include <SDL_mixer.h>
 //..............................................................................
 //..............................................................................
 extern unsigned int     iVerbeux;                              //1=affiche les arguments
