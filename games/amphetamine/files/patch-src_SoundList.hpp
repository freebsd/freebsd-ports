
$FreeBSD$

--- src/SoundList.hpp	2001/01/22 21:09:51	1.1
+++ src/SoundList.hpp	2001/01/22 21:10:20
@@ -6,9 +6,9 @@
 #define _AMPH_SOUND_LIST_
 
 extern "C" {
-#include <SDL/SDL.h>
-#include <SDL/SDL_audio.h>
-#include <SDL/SDL_types.h>
+#include <SDL.h>
+#include <SDL_audio.h>
+#include <SDL_types.h>
 }
 
 class CSound;
@@ -55,4 +55,4 @@
 	SoundState *first, *prev, *current;
 };
 
-#endif 
+#endif 
