--- src/headers.h.orig	2018-08-20 12:55:03 UTC
+++ src/headers.h
@@ -43,11 +43,11 @@ Foundation, 51 Franklin Street, Suite 500, Boston, MA 
 	#include <windows.h>
 #endif
 
-#include "SDL2/SDL.h"
-#include "SDL2/SDL_endian.h"
-#include "SDL2/SDL_image.h"
-#include "SDL2/SDL_mixer.h"
-#include "SDL2/SDL_ttf.h"
+#include <SDL.h>
+#include <SDL_endian.h>
+#include <SDL_image.h>
+#include <SDL_mixer.h>
+#include <SDL_ttf.h>
 
 #include "structs.h"
 #include "i18n.h"
