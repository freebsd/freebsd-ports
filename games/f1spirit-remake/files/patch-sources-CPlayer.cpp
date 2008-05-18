--- sources/CPlayer.cpp.orig	2008-05-17 02:59:23.000000000 +0400
+++ sources/CPlayer.cpp	2008-05-17 03:01:31.000000000 +0400
@@ -204,7 +204,8 @@
 		struct tm *today;
 
 		gettimeofday(&ttime, NULL);
-		today=localtime(&(ttime.tv_sec));
+		time_t tmp = (time_t)ttime.tv_sec;
+		today=localtime(&tmp);
 		
 		position_date[i].year=today->tm_year;
 		position_date[i].month=today->tm_mon;
@@ -231,7 +232,8 @@
 		struct tm *today;
 
 		gettimeofday(&ttime, NULL);
-		today=localtime(&(ttime.tv_sec));
+		time_t tmp = (time_t)ttime.tv_sec;
+		today=localtime(&tmp);
 		
 		time_date[i].year=today->tm_year;
 		time_date[i].month=today->tm_mon;
@@ -258,7 +260,8 @@
 		struct tm *today;
 
 		gettimeofday(&ttime, NULL);
-		today=localtime(&(ttime.tv_sec));
+		time_t tmp = (time_t)ttime.tv_sec;
+		today=localtime(&tmp);
 		
 		lap_date[i].year=today->tm_year;
 		lap_date[i].month=today->tm_mon;
@@ -285,7 +288,8 @@
 		struct tm *today;
 
 		gettimeofday(&ttime, NULL);
-		today=localtime(&(ttime.tv_sec));
+		time_t tmp = (time_t)ttime.tv_sec;
+		today=localtime(&tmp);
 		
 		position_date[i].year=today->tm_year;
 		position_date[i].month=today->tm_mon;
