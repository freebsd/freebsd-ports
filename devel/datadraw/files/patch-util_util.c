--- util/util.c.orig	Fri Aug 31 15:40:23 2007
+++ util/util.c	Fri Aug 31 15:40:29 2007
@@ -158,7 +158,7 @@
 {
     va_list ap;
     char *buff;
-    uint timerID = utTimerDepth++;
+    uint16 timerID = utTimerDepth++;
 
     utTimers[timerID] = time(NULL);
     if(format != NULL) {
