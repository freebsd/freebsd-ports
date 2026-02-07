--- pyramid.c.orig	2016-07-26 13:07:24 UTC
+++ pyramid.c
@@ -67,7 +67,7 @@ getlocaltm()
 	Time_t		ltime;
 
 	time(&ltime);
-	return (localtime(ltime));
+	return (localtime(&ltime));
 #endif	/* MSDOS or UNIX */
 }
 
@@ -197,19 +197,14 @@ char *
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
