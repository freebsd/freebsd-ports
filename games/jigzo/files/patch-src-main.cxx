--- src/main.cxx.orig	2013-09-14 02:26:08.857226185 +0400
+++ src/main.cxx	2013-09-14 02:28:44.311226803 +0400
@@ -56,6 +56,7 @@
 #include <sys/types.h>
 #endif
 #include <dirent.h>
+#include <unistd.h> // for getpid()
 
 #include "Screen.hxx"
 #include "Sprite.hxx"
@@ -1540,7 +1541,7 @@
 		int i;
 		Uint8 *keys = SDL_GetKeyState(&i);
 		SDL_Event event;
-		while (mode!=end) {
+		while (mode!=::end) {
 			//static Uint32 mark = 0;
 			SDL_Delay(10);
 			while (SDL_PollEvent(&event)) {
@@ -1579,7 +1580,7 @@
 				if (clickLeave)
 				{
 					if (mode == intro)
-						FadeOutTo(end_intro,end);
+						FadeOutTo(end_intro,::end);
 					else if (mode == browse) {
 						FadeOutTo(end_browse,start_intro);
 					} else {
@@ -1587,7 +1588,7 @@
 					}
 				}
 				if (event.type == SDL_QUIT) {
-					mode = end;
+					mode = ::end;
 					break;
 				}
 			}
