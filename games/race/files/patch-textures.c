--- src/textures.c.orig	Fri Mar  8 01:44:46 2002
+++ src/textures.c	Sun Jul 21 21:14:50 2002
@@ -33,9 +33,9 @@
 
 int loadtexture(char *dir, char *file, int filter, int repeat, int id){
   SDL_Surface	*image;
-  char		location[6+strlen(dir)+strlen(file)];
+  char		location[60+strlen(dir)+strlen(file)];
   
-  sprintf(location,"data/%s/%s",dir,file);
+  sprintf(location,"%%DATADIR%%/data/%s/%s",dir,file);
 
   if((image = IMG_Load(location))){
     glGenTextures(1, &texture[id]);
