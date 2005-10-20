--- plugins/actor/pseudotoad_flower/notch.c.orig
+++ plugins/actor/pseudotoad_flower/notch.c
@@ -23,6 +23,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 #include <string.h>
 
@@ -30,9 +31,10 @@
 
 NOTCH_FILTER *  init_notch(float cutoff) {
     NOTCH_FILTER * l=malloc(sizeof(NOTCH_FILTER));
-    float steep = 0.99;;
-    float r = steep * 0.99609375;
-    float f = cos(M_PI * cutoff / SAMPLING_RATE);
+    float steep = 0.99;
+    float r,f;
+    r = steep * 0.99609375;
+    f = cos(M_PI * cutoff / SAMPLING_RATE);
     l->cutoff = cutoff;
     l->a0 = (1 - r) * sqrt( r * (r - 4 * (f * f) + 2) + 1);
     l->b1 = 2 * f * r;
