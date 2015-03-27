--- src/main.cxx.orig	2008-05-09 02:39:02.000000000 +0400
+++ src/main.cxx	2015-03-27 17:21:48.934373000 +0300
@@ -47,6 +47,7 @@
 #include <fstream>
 #include <string>
 #include <sstream>
+#include <algorithm>
 
 #ifdef WIN32
 #include <io.h>
@@ -56,6 +57,7 @@
 #include <sys/types.h>
 #endif
 #include <dirent.h>
+#include <unistd.h> // for getpid()
 
 #include "Screen.hxx"
 #include "Sprite.hxx"
@@ -1540,7 +1542,7 @@
 		int i;
 		Uint8 *keys = SDL_GetKeyState(&i);
 		SDL_Event event;
-		while (mode!=end) {
+		while (mode!=::end) {
 			//static Uint32 mark = 0;
 			SDL_Delay(10);
 			while (SDL_PollEvent(&event)) {
@@ -1579,7 +1581,7 @@
 				if (clickLeave)
 				{
 					if (mode == intro)
-						FadeOutTo(end_intro,end);
+						FadeOutTo(end_intro,::end);
 					else if (mode == browse) {
 						FadeOutTo(end_browse,start_intro);
 					} else {
@@ -1587,7 +1589,7 @@
 					}
 				}
 				if (event.type == SDL_QUIT) {
-					mode = end;
+					mode = ::end;
 					break;
 				}
 			}
