--- src/textures.c.orig	Tue Jul 16 23:50:37 2002
+++ src/textures.c	Tue Jul 16 23:50:46 2002
@@ -35,7 +35,7 @@
   SDL_Surface	*image;
   char		location[6+strlen(dir)+strlen(file)];
   
-  sprintf(location,"data/%s/%s",dir,file);
+  sprintf(location,"%%DATADIR%%/data/%s/%s",dir,file);
 
   if((image = IMG_Load(location))){
     glGenTextures(1, &texture[id]);
