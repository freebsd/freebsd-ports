#
# Use CLOCK_REALTIME when CLOCK_MONOTONIC does not exists.
#
--- evdns.c.orig	Wed Nov 29 15:37:46 2006
+++ evdns.c	Wed Nov 29 15:39:14 2006
@@ -793,7 +793,11 @@
 #ifdef DNS_USE_CPU_CLOCK_FOR_ID
 		struct timespec ts;
 		const u16 trans_id = ts.tv_nsec & 0xffff;
+#ifdef CLOCK_MONOTONIC
 		if (clock_gettime(CLOCK_MONOTONIC, &ts))
+#else
+		if (clock_gettime(CLOCK_REALTIME, &ts))
+#endif
 			event_err(1, "clock_gettime");
 #endif
 
