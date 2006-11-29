#
# Define CLOCK_MONOTONIC if FreeBSD < 5.1
#
--- event.h.orig	Wed Nov 29 12:09:48 2006
+++ event.h	Wed Nov 29 12:10:25 2006
@@ -56,6 +56,10 @@
 #define EV_SIGNAL	0x08
 #define EV_PERSIST	0x10	/* Persistant event */
 
+#if defined(__FreeBSD__) && (__FreeBSD_version < 501000)
+#define CLOCK_MONOTONIC	4
+#endif
+
 /* Fix so that ppl dont have to run with <sys/queue.h> */
 #ifndef TAILQ_ENTRY
 #define _EVENT_DEFINED_TQENTRY
