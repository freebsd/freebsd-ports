--- src/sdl/SDL.cpp.orig	Sun Feb  8 14:45:01 2004
+++ src/sdl/SDL.cpp		Tue Feb 10 14:45:09 2004
@@ -621,7 +621,7 @@
   }
 #else
 #define SDL_CALL_STRETCHER \
-        asm volatile("call *%%eax"::"a" (stretcher),"S" (src),"D" (dest))
+        asm volatile("call *%%eax" : "=a" (stretcher),"=S" (src),"=D" (dest))
 #endif
 #else
 #define SDL_CALL_STRETCHER \
