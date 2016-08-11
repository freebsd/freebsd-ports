--- misc2.c.orig	1991-07-16 15:53:02 UTC
+++ misc2.c
@@ -314,10 +314,12 @@ struct direntry *direntry;
 {
 	long diff_tz;
 	long longtime;
+	long t;
 	if (direntry->tz == NO_TZ)		/* none stored */
 		return;
-	diff_tz = (long) direntry->tz * (3600/4) - gettz(); /* diff. in seconds */
-	longtime = mstonix (direntry->date, direntry->time) + diff_tz; /* adj tz */
+	t = mstonix (direntry->date, direntry->time);
+	diff_tz = (long) direntry->tz * (3600/4) - gettz(t); /* diff. in seconds */
+	longtime = t + diff_tz; /* adj tz */
 	mstime (longtime, &direntry->date, &direntry->time);
 }
 #endif /* GETTZ */
