--- src/lib/CircularBuffer.cpp.orig	Tue Jul 10 16:23:18 2007
+++ src/lib/CircularBuffer.cpp	Tue Jul 10 16:28:25 2007
@@ -115,7 +115,7 @@
 	struct timeval the_time;
 	int result = gettimeofday(&the_time, NULL);
 	if(result >= 0){
-		struct tm *pTime = localtime(&the_time.tv_sec);
+		struct tm *pTime = localtime((time_t*)&the_time.tv_sec);
 		sprintf(buffer, "%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
 
 		//append miliseconds
