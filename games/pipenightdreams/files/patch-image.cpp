--- src/image.cpp.orig	Sat Jan  1 14:47:18 2005
+++ src/image.cpp	Sat Jan  1 14:47:24 2005
@@ -19,7 +19,7 @@
 #include "SDL_image.h"
 #include <stdio.h>
 
-Image::Image(Str * filename=NULL):Graphic(){
+Image::Image(Str * filename):Graphic(){
   if (filename) load(filename);
 }
 
