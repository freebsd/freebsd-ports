--- progs/demos/Fractals_random/fractals_random.c.orig	Tue Sep 23 07:17:13 2003
+++ progs/demos/Fractals_random/fractals_random.c	Sat Oct  4 02:43:15 2003
@@ -20,7 +20,7 @@
  *  Escape - quit
  */
 
-#include <GL/freeglut.h>
+#include <../../../include/GL/freeglut.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
@@ -253,7 +253,7 @@
   if ( argc > 1 )
     readConfigFile ( argv[1] ) ;
   else
-    readConfigFile ( "fractals.dat" ) ;
+    readConfigFile ( "/usr/local/share/examples/freeglut/fractals.dat" ) ;
 
   glutInit(&argc, argv);
   glutInitWindowSize(500, 250);
