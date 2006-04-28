$FreeBSD$
--- src/speak.cpp	Fri Mar 24 16:22:56 2006
+++ src/speak.cpp.port	Sat Mar 25 11:50:37 2006
@@ -135,7 +135,7 @@
 	sprintf(path_home,"%s/espeak-data",getenv("HOME"));
 	if(access(path_home,R_OK) != 0)
 	{
-		strcpy(path_home,"/usr/share/espeak-data");
+		strcpy(path_home,"%%DATADIR%%/espeak-data");
 	}
 
 	WavegenInit(22050,0);
