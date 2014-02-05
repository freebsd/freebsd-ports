--- ./src/image.cpp.orig	2002-01-17 20:56:32.000000000 +0100
+++ ./src/image.cpp	2014-02-01 23:41:06.000000000 +0100
@@ -19,7 +19,7 @@
 #include "SDL_image.h"
 #include <stdio.h>
 
-Image::Image(Str * filename=NULL):Graphic(){
+Image::Image(Str * filename):Graphic(){
   if (filename) load(filename);
 }
 
