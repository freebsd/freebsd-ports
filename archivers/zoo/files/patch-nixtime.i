--- ./nixtime.i.orig	1991-07-16 17:53:46.000000000 +0200
+++ ./nixtime.i	2011-12-22 14:00:55.000000000 +0100
@@ -52,7 +52,8 @@
 	long mstonix();
 	long gettz();
 	long utimbuf[2];
-	utimbuf[0] = utimbuf[1] = gettz() + mstonix (date, time);
+	long t = mstonix (date, time);
+	utimbuf[0] = utimbuf[1] = t + gettz(t);
 	return (utime (path, utimbuf));
 }
 
