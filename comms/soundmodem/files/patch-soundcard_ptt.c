--- soundcard/ptt.c.orig	2012-11-07 11:05:55.000000000 -0500
+++ soundcard/ptt.c	2012-11-07 11:06:15.000000000 -0500
@@ -176,7 +176,7 @@
 #endif
 
 	logprintf(MLOG_INFO, "Opening PTT device \"%s\"\n", path);
-	if ((fd = open(path, O_RDWR, 0)) < 0) {
+	if ((fd = open(path, O_RDWR|O_NONBLOCK, 0)) < 0) {
 		logprintf(MLOG_ERROR, "Cannot open PTT device \"%s\"\n", path);
 		return -1;
 	}
