--- include/includes.h.orig	Tue Dec 10 19:50:18 2002
+++ include/includes.h	Tue Dec 10 19:52:33 2002
@@ -808,8 +808,10 @@
 #endif
 
 /* this guess needs to be improved (tridge) */
+#ifndef __FreeBSD__
 #if (defined(STAT_STATVFS) || defined(STAT_STATVFS64)) && !defined(SYSV)
 #define SYSV 1
+#endif
 #endif
 
 #ifndef DEFAULT_PRINTING
