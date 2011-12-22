--- ./zoolist.c.orig	1991-07-20 00:57:27.000000000 +0200
+++ ./zoolist.c	2011-12-22 14:00:55.000000000 +0100
@@ -539,10 +539,12 @@
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
