--- const.h.orig	Tue Mar 10 00:00:00 1998
+++ const.h	Fri Nov 29 17:33:22 2002
@@ -3,12 +3,14 @@
 //   Programming: Gerhard Waldhör, Andreas Artmann
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <errno.h>
 #include <math.h>
 
+#ifndef TRUE
 #define TRUE 1
 #define FALSE 0
+#endif
 
 #define MAX_PIC_NUM 999
 
@@ -83,3 +85,6 @@
 
 #define BW -1 // Borderwidth of objects
 #define ABW abs(BW) // absolute value of BW, needed for 'akima'- and 'wavelet-levels'-plots
+
+#define BROWSER_CMD "mozilla"
+#define BROWSER_MSG "Starts MOZILLA"
