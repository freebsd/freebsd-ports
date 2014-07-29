--- src/libmpeg/mpegtoraw.cc.orig	Mon Dec  8 21:20:37 2003
+++ src/libmpeg/mpegtoraw.cc	Mon Apr 19 23:00:18 2004
@@ -9,8 +9,8 @@
 #include <pthread.h>
 #endif
 
-#include <math.h>
-#include <stdlib.h>
+#include <cmath>
+#include <cstdlib>
 #include <unistd.h>
 
 #include "mpegsound.h"
@@ -419,7 +419,7 @@
   return true;
 }
 
-#include <iostream.h>
+#include <iostream>
 // Convert mpeg to raw
 bool Mpegtoraw::run(int frames) {
   clearrawdata();
