--- src/intervaltimer.C.orig	Tue Jan 31 20:22:04 2006
+++ src/intervaltimer.C	Tue Jan 31 20:22:26 2006
@@ -111,7 +111,7 @@
 	// Some systems define tv_usec as something other than long so we need
 	// to get a long and then let it auto-cast during assignment below.
 	long	usec;
-	bool	retval=getTimeRemaining(&(tv->tv_sec),&usec);
+	bool	retval=getTimeRemaining((long*)(&tv->tv_sec),&usec);
 	tv->tv_usec=usec;
 	return retval;
 }
