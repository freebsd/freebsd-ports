--- src/defendguin.c.orig	2023-06-28 07:54:01 UTC
+++ src/defendguin.c
@@ -4746,6 +4746,7 @@ void setup(void)
               "%s\n\n", SDL_GetError());
       exit(1);
     }
+  atexit(SDL_Quit);
   
   
   /* Open display: */
