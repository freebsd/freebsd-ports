--- src/observator.cpp.orig	Sat Jun 12 17:53:26 2004
+++ src/observator.cpp	Sat Jun 12 17:53:50 2004
@@ -166,25 +166,21 @@
 // Fixed 31-05-2004 Now use the extern variables set by tzset()
 float Observator::get_GMT_shift_from_system(double JD) const
 {
-	return -(float)timezone/3600 + (daylight!=0);
 
 	
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
