--- main.cpp.orig	2013-09-13 20:45:37.434226771 +0400
+++ main.cpp	2013-09-13 20:46:02.845227068 +0400
@@ -34,6 +34,7 @@
 #include <SDL/SDL_image.h>
 #include <math.h>
 #include <string.h>
+#include <unistd.h> // for usleep()
 
 #define ALIEN_SHOOT_DELAY rand() % 5000/(level/5.0f);
 #define NUM_PSYS 20
