On all BSDs the function alloca(3) is declared in stdlib.h.
See also: https://sourceforge.net/p/golly/bugs/62/

--- sound/cute_sound.h.orig	2023-07-15 13:39:21 UTC
+++ sound/cute_sound.h
@@ -624,9 +624,6 @@ cs_plugin_id_t cs_add_plugin(cs_context_t* ctx, const 
 #elif CUTE_SOUND_PLATFORM == CUTE_SOUND_SDL
 
 	#include <SDL2/SDL.h>
-	#ifndef _WIN32
-		#include <alloca.h>
-	#endif
 
 #else
 
