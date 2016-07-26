--- src/libmpeg/mpegtoraw.cc.orig	2003-12-08 12:20:37 UTC
+++ src/libmpeg/mpegtoraw.cc
@@ -9,8 +9,8 @@
 #include <pthread.h>
 #endif
 
-#include <math.h>
-#include <stdlib.h>
+#include <cmath>
+#include <cstdlib>
 #include <unistd.h>
 
 #include "mpegsound.h"
@@ -419,7 +419,7 @@ bool Mpegtoraw::loadheader(void)
   return true;
 }
 
-#include <iostream.h>
+#include <iostream>
 // Convert mpeg to raw
 bool Mpegtoraw::run(int frames) {
   clearrawdata();
