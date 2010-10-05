--- stats.c.orig	2002-03-27 11:02:12.000000000 +0800
+++ stats.c	2010-10-05 09:56:08.000000000 +0800
@@ -157,8 +157,8 @@
 
      logger(LOG_INFO, "  Load measurements:");
      logger(LOG_INFO, "   User: %8.3fs  Sys:%8.3fs",
-            (double)(s_stats.tms.tms_utime) / CLK_TCK,
-            (double)(s_stats.tms.tms_stime) / CLK_TCK);
+            (double)(s_stats.tms.tms_utime) / CLOCKS_PER_SEC,
+            (double)(s_stats.tms.tms_stime) / CLOCKS_PER_SEC);
      logger(LOG_INFO, "   Total:%8.3fs  CPU:%8.3f%%", 
             (double)(tmp.tv_sec + tmp.tv_usec * 1e-6),
             (double)(s_stats.tms.tms_utime + s_stats.tms.tms_stime) /
