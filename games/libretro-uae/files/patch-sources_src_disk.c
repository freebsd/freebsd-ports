--- sources/src/disk.c.orig	2020-03-18 00:12:17 UTC
+++ sources/src/disk.c
@@ -282,7 +282,6 @@ static void disk_date (uae_u8 *p)
 	struct mytimeval mtv;
 
 	gettimeofday (&tv, NULL);
-	tv.tv_sec -= timezone;
 	mtv.tv_sec = tv.tv_sec;
 	mtv.tv_usec = tv.tv_usec;
 	timeval_to_amiga (&mtv, &days, &mins, &ticks);
