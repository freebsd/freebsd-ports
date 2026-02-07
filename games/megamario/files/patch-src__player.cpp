--- ./src/player.cpp.orig	2014-01-13 00:20:08.000000000 +0100
+++ ./src/player.cpp	2014-01-13 00:20:08.000000000 +0100
@@ -10,7 +10,9 @@
 #include "Global.h"
 
 //#include <Math.h>
+#ifndef M_PI
 #define M_PI 3.141592654
+#endif
 
 
 #define JUMPS 12
