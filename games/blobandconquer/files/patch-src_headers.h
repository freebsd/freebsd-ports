--- src/headers.h.orig	Tue May 30 23:08:58 2006
+++ src/headers.h	Tue May 30 23:09:11 2006
@@ -20,6 +20,7 @@
 
 #define GL_GLEXT_PROTOTYPES
 
+#include "unistd.h"
 #include "stdlib.h"
 #include "stdio.h"
 #include "string.h"
@@ -30,11 +31,11 @@
 
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
