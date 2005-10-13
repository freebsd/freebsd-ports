
$FreeBSD$

--- main.cpp.orig
+++ main.cpp
@@ -12,6 +12,7 @@
 
 #include "main.h"
 #include "interface.h"
+#include <math.h>
 
 
 // SDL stuff
@@ -210,11 +211,11 @@
 			Yc = (luma[j+1] - 2.0)* 255.0 / (5.0 - 2.0); // 5V is the base voltage
 			// RED, GREEN and BLUE component
 			colorindex = (j)*16*3 + i*3;
-			col = (Uint8) max(min((Yc + 1.367 * Vc),255.0),0);
+			col = (Uint8) fmax(fmin((Yc + 1.367 * Vc),255.0),0);
 			p4col_calc[ colorindex ] = p4col_calc[ 384 + colorindex ] = col;
-			col = (Uint8) max(min((Yc - 0.336 * Uc - 0.698 * Vc ),255.0),0);
+			col = (Uint8) fmax(fmin((Yc - 0.336 * Uc - 0.698 * Vc ),255.0),0);
 			p4col_calc[ colorindex + 1] = p4col_calc[ 384 + colorindex + 1] = col;
-			col = (Uint8) max(min((Yc + 1.732 * Uc),255.0),0);
+			col = (Uint8) fmax(fmin((Yc + 1.732 * Uc),255.0),0);
 			p4col_calc[ colorindex + 2] = p4col_calc[ 384 + colorindex + 2] = col;
 		}
 
