--- code/main.cpp.orig	Mon Mar 15 23:00:40 2004
+++ code/main.cpp	Mon Mar 15 23:00:50 2004
@@ -29,7 +29,7 @@
     #include "life.h"
     #include "lifeController.h"
         extern "C" int
-        SDL_main( int argc, char** argv )
+        main( int argc, char** argv )
         {
                 unsigned int initFlags = 0;
                 initFlags |= SDL_INIT_VIDEO;
