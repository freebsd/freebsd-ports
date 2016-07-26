--- nixtime.i.orig	1991-07-16 15:53:46 UTC
+++ nixtime.i
@@ -52,7 +52,8 @@ unsigned int date, time;
 	long mstonix();
 	long gettz();
 	long utimbuf[2];
-	utimbuf[0] = utimbuf[1] = gettz() + mstonix (date, time);
+	long t = mstonix (date, time);
+	utimbuf[0] = utimbuf[1] = t + gettz(t);
 	return (utime (path, utimbuf));
 }
 
