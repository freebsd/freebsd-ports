--- sdlconst.c.old	Wed Oct  5 02:49:32 2005
+++ sdlconst.c	Wed Oct  5 02:49:42 2005
@@ -8,8 +8,8 @@
 #include "stdlib.h"
 #include "string.h"
 #include "math.h"
-#include "SDL/SDL_endian.h"
-#include "SDL/SDL.h"
+#include "SDL11/SDL_endian.h"
+#include "SDL11/SDL.h"
 
 
 typedef struct {PyObject **p; char *s;} __Pyx_InternTabEntry; /*proto*/
