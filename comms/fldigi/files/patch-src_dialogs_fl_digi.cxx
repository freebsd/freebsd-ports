--- src/dialogs/fl_digi.cxx.orig	2009-11-08 15:02:38.000000000 -0500
+++ src/dialogs/fl_digi.cxx	2010-05-27 08:02:45.000000000 -0400
@@ -25,6 +25,7 @@
 #include <config.h>
 
 #include <sys/types.h>
+#include <time.h>
 
 #ifdef __WOE32__
 #  ifdef __CYGWIN__
@@ -1349,7 +1350,7 @@
 	Fl::repeat_timeout(st, ztimer);
 
 	struct tm tm;
-	gmtime_r(&tv.tv_sec, &tm);
+	gmtime_r((const time_t *)&tv.tv_sec, &tm);
 	if (!strftime(ztbuf, sizeof(ztbuf), "%Y%m%d %H%M", &tm))
 		memset(ztbuf, 0, sizeof(ztbuf));
 	else
