--- src/lib/plt/shl/cclk.cxx.orig	Fri Jul 14 12:03:50 2006
+++ src/lib/plt/shl/cclk.cxx	Thu Aug  3 13:58:51 2006
@@ -58,8 +58,8 @@ namespace afnix {
     // initialize local and utc structure
     struct tm utm;
     struct tm ltm;
-    if (gmtime_r    (&(tval.tv_sec), &utm) == NULL) return 0;
-    if (localtime_r (&(tval.tv_sec), &ltm) == NULL) return 0;
+    if (gmtime_r    ((time_t *)&(tval.tv_sec), &utm) == NULL) return 0;
+    if (localtime_r ((time_t *)&(tval.tv_sec), &ltm) == NULL) return 0;
     // compute local time in second
     t_long lts = (ltm.tm_yday * 86400) + (ltm.tm_hour * 3600) + 
                  (ltm.tm_min  * 60) + ltm.tm_sec;
