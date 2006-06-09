--- examples/SDLExample/main.cpp.orig	Tue Jun  6 21:18:47 2006
+++ examples/SDLExample/main.cpp	Tue Jun  6 21:18:58 2006
@@ -3,7 +3,7 @@
 #ifdef PLATFORM_WIN32
 #include <SDL.h>
 #else
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 #endif
 
 const int maxpoint  = 1000;
