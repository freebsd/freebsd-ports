--- imms.cc.orig	Wed Feb 11 17:47:21 2004
+++ imms.cc	Wed Feb 11 18:03:41 2004
@@ -1,7 +1,6 @@
 #include <time.h>
 #include <ctype.h>
 #include <math.h>
-#include <stdlib.h>     // for (s)random
 
 #include <iostream>
 #include <iomanip>
@@ -43,23 +42,6 @@
 //////////////////////////////////////////////
 
 string last_song;
-
-// Random
-int imms_random(int max)
-{
-    int rand_num;
-    static struct random_data rand_data;
-    static char rand_state[256];
-    static bool initialized = false;
-    if (!initialized)
-    {
-        initstate_r(time(0), rand_state, sizeof(rand_state), &rand_data);
-        initialized = true;
-    }
-    random_r(&rand_data, &rand_num);
-    double cof = rand_num / (RAND_MAX + 1.0);
-    return (int)(max * cof);
-}
 
 // Imms
 Imms::Imms() 
