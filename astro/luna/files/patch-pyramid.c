--- pyramid.c.orig	Mon May 25 01:26:10 1992
+++ pyramid.c	Mon Feb 21 02:23:51 2000
@@ -67,7 +67,7 @@
 	Time_t		ltime;
 
 	time(&ltime);
-	return (localtime(ltime));
+	return (localtime(&ltime));
 #endif	/* MSDOS or UNIX */
 }
 
@@ -197,19 +197,14 @@
 Asctime(struct tm *tmp)
 {
 	static char	s[LASCTIME];
-	char		*tzname;
 
-	if ((tzname = getenv("TZ")) == NULL) {
-		tzname = TZNAME_DFL;
-	}
-	sprintf(s, "%s %s %2d %02d:%02d:%02d %4d %3.3s\n",
+	sprintf(s, "%s %s %2d %4d %02d:%02d:%02d\n",
 			downame[ymd2wday(tmp -> tm_year, tmp -> tm_mon,
 								 tmp -> tm_mday)],
 			capitalize(monname[tmp -> tm_mon]),
 			tmp -> tm_mday,
-			tmp -> tm_hour, tmp -> tm_min, tmp -> tm_sec,
 			tmp -> tm_year + 1900,
-			tzname
+			tmp -> tm_hour, tmp -> tm_min, tmp -> tm_sec,
 		   );
 
 	return (s);
