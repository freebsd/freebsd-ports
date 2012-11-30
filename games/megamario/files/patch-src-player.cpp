--- src/player.cpp.orig	2012-05-05 20:22:06.000000000 +0200
+++ src/player.cpp	2012-05-05 21:08:10.000000000 +0200
@@ -10,7 +10,9 @@
 #include "Global.h"
 
 //#include <Math.h>
+#ifndef M_PI
 #define M_PI 3.141592654
+#endif
 
 
 #define JUMPS 12
