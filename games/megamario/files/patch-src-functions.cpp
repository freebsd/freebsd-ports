--- src/functions.cpp.orig	2012-05-06 00:56:40.000000000 +0200
+++ src/functions.cpp	2012-05-06 01:00:37.000000000 +0200
@@ -447,7 +447,7 @@
 	}
 	else
 	{
-		sprintf(tmp, "mp3music/%s",filename);
+		sprintf(tmp, DATADIR "mp3music/%s",filename);
 		tmp[strlen(tmp)-3]='m';
 		tmp[strlen(tmp)-2]='p';
 		tmp[strlen(tmp)-1]='3';
