--- progs/demos/Lorenz/lorenz.c.orig	Thu Dec 11 02:32:08 2003
+++ progs/demos/Lorenz/lorenz.c	Sat Dec 13 10:19:26 2003
@@ -32,7 +32,7 @@
 #include <string.h>
 #include <math.h>
 #include <time.h>
-#include <GL/freeglut.h>
+#include "../../../include/GL/freeglut.h"
 #ifdef WIN32
 #include <crtdbg.h>  // DUMP MEMORY LEAKS
 #endif
