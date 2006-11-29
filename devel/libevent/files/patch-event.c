#
# Use CLOCK_REALTIME when CLOCK_MONOTONIC does not exists.
#
--- event.c.orig	Wed Nov 29 15:37:37 2006
+++ event.c	Wed Nov 29 15:38:39 2006
@@ -150,7 +150,11 @@
 #ifdef HAVE_CLOCK_GETTIME
 	struct timespec	ts;
 	
+#ifdef CLOCK_MONOTONIC
 	if (clock_gettime(CLOCK_MONOTONIC, &ts) == -1)
+#else
+	if (clock_gettime(CLOCK_REALTIME, &ts) == -1)
+#endif
 		return (-1);
 	tp->tv_sec = ts.tv_sec;
 	tp->tv_usec = ts.tv_nsec / 1000;
