--- progs/demos/Fractals/fractals.c.orig	Sun Sep 21 15:47:36 2003
+++ progs/demos/Fractals/fractals.c	Mon Sep 29 23:35:43 2003
@@ -18,7 +18,7 @@
  *  Escape - quit
  */
 
-#include <GL/freeglut.h>
+#include "../../../include/GL/freeglut.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
@@ -262,7 +262,7 @@
   if ( argc > 1 )
     readConfigFile ( argv[1] ) ;
   else
-    readConfigFile ( "fractals.dat" ) ;
+    readConfigFile ( "/usr/local/share/examples/freeglut/fractals.dat" ) ;
 
   glutInit(&argc, argv);
   glutInitWindowSize(500, 250);
