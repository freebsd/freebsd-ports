--- src/headers.h.orig	Mon Apr  3 05:24:55 2006
+++ src/headers.h	Mon Apr  3 05:26:10 2006
@@ -18,7 +18,7 @@
 
 */
 
-#include "mcheck.h"
+#include <unistd.h>
 #include "stdlib.h"
 #include "stdio.h"
 #include "string.h"
@@ -29,11 +29,11 @@
 
 #include "zlib.h"
 
-#include "SDL/SDL.h"
-#include "SDL/SDL_image.h"
-#include "SDL/SDL_mixer.h"
-#include "SDL/SDL_ttf.h"
-#include "SDL/SDL_endian.h"
+#include "SDL11/SDL.h"
+#include "SDL11/SDL_image.h"
+#include "SDL11/SDL_mixer.h"
+#include "SDL11/SDL_ttf.h"
+#include "SDL11/SDL_endian.h"
 
 #include "GL/gl.h"
 #include "GL/glu.h"
