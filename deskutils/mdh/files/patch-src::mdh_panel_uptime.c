--- src/mdh_panel_uptime.c.orig	Wed Nov 12 05:38:41 2003
+++ src/mdh_panel_uptime.c	Wed Nov 12 05:45:55 2003
@@ -40,6 +40,7 @@
 
 #ifdef BSD4_4
 #include <sys/sysctl.h>
+#include <sys/time.h>
 #endif
 
 #ifdef __sun__
@@ -227,7 +228,7 @@
 
 #ifdef BSD4_4
     if(sysctl(mib, 2, &btime, &size, NULL, 0) != -1 && btime.tv_sec != 0)
-        sec = (time(NULL) - boottime.tv_sec) + 30;
+        sec = (time(NULL) - btime.tv_sec) + 30;
 #endif
 
     *seconds = sec;
