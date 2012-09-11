--- defendguin.c.orig	2009-11-05 22:20:59.000000000 +0100
+++ defendguin.c	2012-09-10 22:01:37.000000000 +0200
@@ -4322,6 +4322,7 @@
               "%s\n\n", SDL_GetError());
       exit(1);
     }
+  atexit(SDL_Quit);
   
   
   /* Open display: */
