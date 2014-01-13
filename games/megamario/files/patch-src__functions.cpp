--- ./src/functions.cpp.orig	2014-01-13 00:20:08.000000000 +0100
+++ ./src/functions.cpp	2014-01-13 00:20:08.000000000 +0100
@@ -447,7 +447,7 @@
 	}
 	else
 	{
-		sprintf(tmp, "mp3music/%s",filename);
+		sprintf(tmp, DATADIR "mp3music/%s",filename);
 		tmp[strlen(tmp)-3]='m';
 		tmp[strlen(tmp)-2]='p';
 		tmp[strlen(tmp)-1]='3';
