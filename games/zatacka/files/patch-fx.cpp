--- fx.cpp.orig	Mon Mar 27 00:43:47 2006
+++ fx.cpp	Mon Mar 27 00:47:47 2006
@@ -46,8 +46,6 @@
 	int i;
 	char* wd;
 
-	wd=GetAppPath(); //get path to aplication directory
-	chdir(wd); //change working directory to aplication directory
 
 	if((SDL_Init(SDL_INIT_VIDEO ))==-1){ //initialize SDL library
 		disperr("Error initializing SDL");
