
$FreeBSD$

--- graphics/i_sdl.c	2002/04/17 17:57:00	1.1
+++ graphics/i_sdl.c	2002/04/17 17:57:08
@@ -7,7 +7,7 @@
 #include <sys/time.h>
 #include "doomdef.h"
 
-#include "SDL/SDL.h"
+#include "SDL.h"
 
 static int      lastmousex = 0;
 static int      lastmousey = 0;                                            
