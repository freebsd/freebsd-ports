--- src/Ylib/timer.c.orig	2018-08-23 20:02:57 UTC
+++ src/Ylib/timer.c
@@ -58,6 +58,23 @@ REVISIONS:  
 #include <sys/timeb.h>
 #endif /* SYS5 */
 
+#include <sys/time.h>
+
+// from /usr/src/lib/libcompat/4.1/ftime.c
+int ftime(struct timeb *tbp) {
+	struct timezone tz;
+	struct timeval t;
+
+	if (gettimeofday(&t, &tz) < 0)
+		return (-1);
+	tbp->millitm = t.tv_usec / 1000;
+	tbp->time = t.tv_sec;
+	tbp->timezone = tz.tz_minuteswest;
+	tbp->dstflag = tz.tz_dsttime;
+
+	return (0);
+}
+
 static INT base_timeS = 0 ;       /* the time in seconds at the start */
 static INT milli_timeS ;         /* the millisecond part of the start */
 /* initialize the timer */
