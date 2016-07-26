--- zoolist.c.orig	1991-07-19 22:57:27 UTC
+++ zoolist.c
@@ -539,10 +539,12 @@ int file_tz;
 {
 	long gettz();
 	int diff_tz;				/* timezone difference */
+	long t;
 	if (file_tz == NO_TZ) 	/* if no timezone stored ..*/
 		printf ("   ");			/* .. just pad with blanks */
 	else {
-		diff_tz = (file_tz / 4) - (int) (gettz() / 3600);
+		time(&t);
+		diff_tz = (file_tz / 4) - (int) (gettz(t) / 3600);
 		if (diff_tz == 0)
 			printf ("   ");					/* print nothing if same */
 		else if (diff_tz > 0)			/* else print signed difference */
