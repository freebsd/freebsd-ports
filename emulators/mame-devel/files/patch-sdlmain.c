--- src/osd/sdl/sdlmain.c.orig	2009-11-01 01:22:48.000000000 +0100
+++ src/osd/sdl/sdlmain.c	2009-11-01 01:23:26.000000000 +0100
@@ -78,7 +78,7 @@
 #ifdef MESS
 	#define INI_PATH "$HOME/.mess;.;ini"
 #else
-	#define INI_PATH "$HOME/.mame;.;ini"
+	#define INI_PATH "$HOME/.mame-devel;.;ini"
 #endif // MESS
 #endif // MACOSX
 #endif // INI_PATH
