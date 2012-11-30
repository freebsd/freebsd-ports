--- src/main.cpp.orig	2012-05-06 00:56:40.000000000 +0200
+++ src/main.cpp	2012-05-06 01:03:55.000000000 +0200
@@ -61,7 +61,7 @@
 
 #endif /* defined __unix__ */
 
-	out_logfile.open ("log.txt");
+	out_logfile.open ("%s/.megamario/log.txt");
 
 	dictionary * d = iniparser_new(szIniFile);
 	pixelation = iniparser_getboolean (d, "Mario:Pixelation", 1);
@@ -413,7 +413,7 @@
 
 
 fstream fin;
-fin.open("mp3music/music_available.dat",ios::in);
+fin.open( DATADIR "mp3music/music_available.dat",ios::in);
 if( fin.is_open() )
 {
 	HighQualityMusicFound=1;
