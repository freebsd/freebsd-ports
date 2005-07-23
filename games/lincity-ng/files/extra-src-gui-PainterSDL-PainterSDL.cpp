--- src/gui/PainterSDL/PainterSDL.cpp.orig	Fri Jul 15 19:47:12 2005
+++ src/gui/PainterSDL/PainterSDL.cpp	Sat Jul 23 12:41:09 2005
@@ -30,10 +30,8 @@
 
 #include "TextureSDL.hpp"
 
-#ifdef _MSC_VER
 #define lrint(x) (long int)x
 #define lroundf(x) (long int)(x + .5)
-#endif
 
 PainterSDL::PainterSDL(SDL_Surface* _target)
     : target(_target)
