--- tools/avg4.c.orig	Thu Mar 10 20:47:48 2005
+++ tools/avg4.c	Thu Mar 10 20:48:11 2005
@@ -34,7 +34,7 @@
 #include <stdio.h>
 #include "rle.h"
 
-static bit_count[16] = {0, 63, 63, 127, 63, 127, 127,
+static int bit_count[16] = {0, 63, 63, 127, 63, 127, 127,
     192, 63, 127, 127, 192, 127, 192, 192, 255};
 
 void
