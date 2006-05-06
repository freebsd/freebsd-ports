--- src/intervaltimer.C.orig	Sat Sep 24 00:31:57 2005
+++ src/intervaltimer.C	Wed May  3 18:08:55 2006
@@ -134,7 +134,7 @@
 	// assignment below.
 	long	sec;
 	long	usec;
-	bool	retval=getTimeRemaining(&sec,&usec);
+	bool	retval=getTimeRemaining((long*)(&sec),&usec);
 	tv->tv_sec=sec;
 	tv->tv_usec=usec;
 	return retval;
