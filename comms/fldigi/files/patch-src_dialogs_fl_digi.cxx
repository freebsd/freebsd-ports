--- src/dialogs/fl_digi.cxx.orig	2009-08-24 13:16:59.000000000 -0400
+++ src/dialogs/fl_digi.cxx	2009-08-24 13:17:51.000000000 -0400
@@ -25,6 +25,7 @@
 #include <config.h>
 
 #include <sys/types.h>
+#include <time.h>
 
 #ifdef __CYGWIN__
 #  include <w32api/windows.h>
@@ -1310,7 +1311,7 @@
 	Fl::repeat_timeout(st, ztimer);
 
 	struct tm tm;
-	gmtime_r(&tv.tv_sec, &tm);
+	gmtime_r((const time_t *)&tv.tv_sec, &tm);
 	if (!strftime(ztbuf, sizeof(ztbuf), "%Y%m%d %H%M", &tm))
 		memset(ztbuf, 0, sizeof(ztbuf));
 	else
