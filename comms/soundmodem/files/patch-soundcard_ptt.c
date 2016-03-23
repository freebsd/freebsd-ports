--- soundcard/ptt.c.orig	2014-09-01 16:22:57 UTC
+++ soundcard/ptt.c
@@ -250,7 +250,7 @@ int pttinit(struct pttio *state, const c
 		return 0;
 	}
 	logprintf(MLOG_INFO, "Opening PTT device \"%s\"\n", path);
-	if ((fd = open(path, O_RDWR, 0)) < 0) {
+	if ((fd = open(path, O_RDWR|O_NONBLOCK, 0)) < 0) {
 		logprintf(MLOG_ERROR, "Cannot open PTT device \"%s\"\n", path);
 		return -1;
 	}
