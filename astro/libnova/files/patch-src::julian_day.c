--- src/julian_day.c.orig	Wed Jul 30 22:53:43 2003
+++ src/julian_day.c	Wed Jul 30 22:54:56 2003
@@ -317,8 +317,14 @@
 */
 void get_local_date (double JD, struct ln_date * date)
 {
+	time_t curtime;
+	struct tm * loctime;
+
+	curtime = time (NULL);
+	loctime = localtime(&curtime);
+
 	/* add timezone to JD */
-	JD += (double)timezone / (24 * 60 * 60);
+ 	JD += ((double)loctime->tm_gmtoff) / (24.0 * 60.0 * 60.0);	
 	
 	get_date (JD, date);
 }
