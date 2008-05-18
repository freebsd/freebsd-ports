--- sources/F1SpiritGame.cpp.orig	2006-02-18 13:33:34.000000000 +0300
+++ sources/F1SpiritGame.cpp	2008-05-17 04:03:21.000000000 +0400
@@ -1615,7 +1615,8 @@
 					struct tm *today;
 
 					gettimeofday(&ttime, NULL);
-					today=localtime(&(ttime.tv_sec));
+					time_t tmp = ttime.tv_sec;
+					today=localtime(&tmp);
 					
 					fputc(today->tm_year,replay_fp);
 					fputc(today->tm_mon,replay_fp);
