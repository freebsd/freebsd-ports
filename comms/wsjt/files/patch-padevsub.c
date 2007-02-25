--- padevsub.c.orig	Mon Feb 19 23:15:39 2007
+++ padevsub.c	Mon Feb 19 23:15:50 2007
@@ -1,6 +1,6 @@
 // #include <stdio.h>
 // #include <math.h>
-#include "portaudio.h"
+#include <portaudio2/portaudio.h>
 
 int __stdcall PADEVSUB(int *numdev, int *ndefin, int *ndefout,
 		       int nchin[], int nchout[])
