--- progs/demos/Fractals_random/fractals_random.c.orig	Thu Dec 11 02:32:08 2003
+++ progs/demos/Fractals_random/fractals_random.c	Sat Dec 13 10:17:10 2003
@@ -20,7 +20,7 @@
  *  Escape - quit
  */
 
-#include <GL/freeglut.h>
+#include "../../../include/GL/freeglut.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
@@ -346,7 +346,7 @@
   if ( argc > 1 )
     readConfigFile ( argv[1] ) ;
   else
-    readConfigFile ( "fractals.dat" ) ;
+    readConfigFile ( "/usr/local/share/examples/freeglut/fractals.dat" ) ;
 
   fractal_window = glutCreateWindow( window_title );
 
