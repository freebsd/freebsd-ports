--- src/game.c.orig	Thu Feb 19 22:33:32 2004
+++ src/game.c	Thu Feb 19 22:33:44 2004
@@ -15,6 +15,7 @@
 #include "graphics.h"
 #include "hiscore.h"
 
+GString* levelset_get_file_name( gchar* file_name );
 
 /**
  * Set up a random seed and set the levels to the first ones.
@@ -271,8 +272,6 @@
   
   va_list varptr;
   gchar msg[255];
-  
-  varptr = NULL;
   
   va_start( varptr, format );
   
