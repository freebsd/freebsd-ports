
$FreeBSD$

--- defendguin.c	2001/02/08 11:27:54	1.1
+++ defendguin.c	2001/02/08 11:37:39
@@ -4058,7 +4058,7 @@
               "%s\n\n", SDL_GetError());
       exit(1);
     }
-  
+  atexit(SDL_Quit);
   
   /* Open display: */
   
@@ -4329,9 +4329,9 @@
                   "%s\n"
                   "The Simple DirectMedia error that occured was:\n"
                   "%s\n\n", MUS_TITLE, SDL_GetError());
-          exit(1);
         }
-      Mix_PlayMusic(title_music, 0);
+      else
+          Mix_PlayMusic(title_music, 0);
 
 
       last_music = Mix_LoadMUS(MUS_LAST);
@@ -4342,7 +4342,6 @@
                   "%s\n"
                   "The Simple DirectMedia error that occured was:\n"
                   "%s\n\n", MUS_LAST, SDL_GetError());
-          exit(1);
         }
 
 
@@ -4354,7 +4353,6 @@
                   "%s\n"
                   "The Simple DirectMedia error that occured was:\n"
                   "%s\n\n", MUS_WIN, SDL_GetError());
-          exit(1);
         }
       
       
@@ -4366,7 +4364,6 @@
                   "%s\n"
                   "The Simple DirectMedia error that occured was:\n"
                   "%s\n\n", MUS_TETRIS, SDL_GetError());
-          exit(1);
         }
       
       
@@ -4380,7 +4377,6 @@
                       "%s\n"
                       "The Simple DirectMedia error that occured was:\n"
                       "%s\n\n", game_music_names[i], SDL_GetError());
-              exit(1);
             }
         }
     }
