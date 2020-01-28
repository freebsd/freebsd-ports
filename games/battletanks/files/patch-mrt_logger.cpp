--- mrt/logger.cpp.orig	2008-09-11 09:12:44.000000000 +0200
+++ mrt/logger.cpp	2008-09-11 09:14:32.000000000 +0200
@@ -81,7 +81,7 @@
 	gettimeofday(&tv, NULL);
 	
 	struct tm tm;
-	localtime_r(&tv.tv_sec, &tm);
+	localtime_r((time_t *)&tv.tv_sec, &tm);
 	
 	h = tm.tm_hour;
 	m = tm.tm_min;
