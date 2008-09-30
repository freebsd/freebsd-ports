--- hex_puzzzle.cpp.orig	2006-02-21 07:12:34.000000000 +0300
+++ hex_puzzzle.cpp	2008-09-14 21:34:14.296378652 +0400
@@ -2313,7 +2313,7 @@
 
 	SDL_Surface* Load(const char * bmp, bool colourKey=true)
 	{
-		typedef unsigned long uint32;
+		typedef unsigned int uint32;
 		uint32* tmp = 0;
 
 		SDL_Surface * g = 0;
