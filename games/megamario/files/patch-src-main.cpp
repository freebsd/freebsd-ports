--- src/main.cpp.orig	2013-09-20 13:22:00.000000000 +0200
+++ src/main.cpp	2013-09-20 13:23:53.000000000 +0200
@@ -61,7 +61,7 @@
 
 #endif /* defined __unix__ */
 
-	out_logfile.open ("log.txt");
+	out_logfile.open ("%s/.megamario/log.txt");
 
 	dictionary * d = iniparser_new(szIniFile);
 	pixelation = iniparser_getboolean (d, "Mario:Pixelation", 1);
@@ -238,7 +238,7 @@
 
 			if(event.key.keysym.sym == SDLK_F12)
 			{
-				char gammel[100];
+				char *gammel = new char[100];
 				sprintf(gammel,"screenshots/%d.bmp",rand()%10000);
 				SDL_SaveBMP(screen,gammel);				
 				delete[] gammel;
@@ -413,7 +413,7 @@
 
 
 fstream fin;
-fin.open("mp3music/music_available.dat",ios::in);
+fin.open( DATADIR "mp3music/music_available.dat",ios::in);
 if( fin.is_open() )
 {
 	HighQualityMusicFound=1;
