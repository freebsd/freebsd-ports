
$FreeBSD$

--- defendguin.c	2002/03/05 13:16:46	1.1
+++ defendguin.c	2002/03/05 13:22:13
@@ -4210,6 +4210,7 @@
               "%s\n\n", SDL_GetError());
       exit(1);
     }
+  atexit(SDL_Quit);
   
   
   /* Open display: */
