--- main.c.orig
+++ main.c
@@ -1,4 +1,7 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
 #include <X11/Xlib.h>
 #include <math.h>
 #include "struct.h"
@@ -160,7 +163,7 @@
 int x;
 {     
   int z1, z2, z3, z4, z=0;
-  char nn[6];
+  static char nn[6];
 
   z1 = (int) (x)/1000;
   z2 = (int) (x)/100-(10*z1);
