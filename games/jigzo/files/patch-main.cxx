--- main.cxx.orig	Sun Feb  5 04:41:46 2006
+++ main.cxx	Sun Feb  5 23:41:41 2006
@@ -28,6 +28,7 @@
 float BG_G = 0.0;
 float BG_B = 0.0;
 
+#include <unistd.h>
 #include <cstdio>
 #include <cstring>
 #include <cmath>
