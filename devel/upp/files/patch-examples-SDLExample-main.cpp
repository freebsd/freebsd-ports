--- examples/SDLExample/main.cpp.orig	Sat Mar  4 17:47:29 2006
+++ examples/SDLExample/main.cpp	Sat Mar  4 17:47:41 2006
@@ -1,6 +1,6 @@
 #include <Core/Core.h>
 
-#ifdef PLATFORM_WIN32
+#if defined PLATFORM_WIN32 || defined PLATFORM_FREEBSD
 #include <SDL.h>
 #else
 #include <SDL/SDL.h>
