--- pyro.c.orig
+++ pyro.c
@@ -7,15 +7,18 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <math.h>
 #ifdef __EMX__ /*os2*/
 #include "float.h"
 #endif
 #include <time.h>
 
+/*
 #ifdef XMESA
 #include <GL/xmesa.h>
 #endif
+*/
 
 #include <GL/glut.h>
 #include "pyro.h"
@@ -704,8 +707,9 @@
       if(fxwin)
 	glutReshapeWindow(ScreenWidth,ScreenHeight);
       else glutFullScreen();
-
+/*
       XMesaSetFXmode(fxwin ? XMESA_FX_WINDOW:XMESA_FX_FULLSCREEN);
+*/
     }
     break;
 #endif
