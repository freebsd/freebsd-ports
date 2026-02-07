--- source/main.cpp.orig	Thu Apr  6 04:19:16 2006
+++ source/main.cpp	Thu Apr  6 04:19:38 2006
@@ -19,6 +19,8 @@
 
 //#include "stdafx.h"
 
+#include <unistd.h>
+#include <string.h>
 #include <SDL.h>
 #include <SDL_opengl.h>
 #include <vorbis/vorbisfile.h>
@@ -1354,6 +1356,7 @@
 
 int main(int argc, char **argv)
 {
+	chdir(getenv("HOME"));
 #ifdef NO_SOUND
 	if (SDL_Init(SDL_INIT_VIDEO) < 0)
 #else
