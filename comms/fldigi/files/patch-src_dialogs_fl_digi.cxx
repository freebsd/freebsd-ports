--- src/dialogs/fl_digi.cxx.orig	2011-12-01 12:03:25.000000000 -0500
+++ src/dialogs/fl_digi.cxx	2011-12-05 16:02:10.000000000 -0500
@@ -26,6 +26,7 @@
 #include <config.h>
 
 #include <sys/types.h>
+#include <time.h>
 
 #ifdef __WOE32__
 #  ifdef __CYGWIN__
@@ -1884,7 +1885,7 @@
 	Fl::repeat_timeout(st, ztimer);
 
 	struct tm tm;
-	gmtime_r(&tv.tv_sec, &tm);
+	gmtime_r((const time_t *)&tv.tv_sec, &tm);
 	if (!strftime(ztbuf, sizeof(ztbuf), "%Y%m%d %H%M", &tm))
 		memset(ztbuf, 0, sizeof(ztbuf));
 	else
