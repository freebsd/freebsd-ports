--- src/headers.h.orig	2018-08-20 12:55:03 UTC
+++ src/headers.h
@@ -43,11 +43,11 @@ Foundation, 51 Franklin Street, Suite 500, Boston, MA 
 	#include <windows.h>
 #endif
 
-#include "SDL/SDL.h"
-#include "SDL/SDL_endian.h"
-#include "SDL/SDL_image.h"
-#include "SDL/SDL_mixer.h"
-#include "SDL/SDL_ttf.h"
+#include <SDL/SDL.h>
+#include <SDL/SDL_endian.h>
+#include <SDL/SDL_image.h>
+#include <SDL/SDL_mixer.h>
+#include <SDL/SDL_ttf.h>
 
 #include "structs.h"
 #include "i18n.h"
