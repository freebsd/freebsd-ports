--- src/observator.cpp.orig	Sat Jan 15 03:19:14 2005
+++ src/observator.cpp	Sat Jan 15 03:20:57 2005
@@ -174,27 +174,23 @@
 	// + (timeinfo->tm_isdst!=0);
 	// only tells if dst is in effect for actual time, not drawn time
 #else
-	return -(float)timezone/3600;
 	// no portable dst method implemented yet, so just standard time for all platforms
 
 #endif
 	
-/*	time_t rawtime = get_time_t_from_julian(JD);
+	time_t rawtime = get_time_t_from_julian(JD);
 
 	struct tm * timeinfo;
 	timeinfo = localtime(&rawtime);
 	static char heure[20];
 	heure[0] = '\0';
 	my_strftime(heure, 19, "%z", timeinfo);
-	cout << heure << endl;
 
-	cout << timezone << endl;
 	
 	heure[5] = '\0';
 	float min = 1.f/60.f * atoi(&heure[3]);
 	heure[3] = '\0';
 	return min + atoi(heure);
-	*/
 }
 
 // Return the time in ISO 8601 format that is : %Y-%m-%d %H:%M:%S
