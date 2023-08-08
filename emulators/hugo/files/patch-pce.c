--- pce.c.orig	2005-03-28 14:17:45 UTC
+++ pce.c
@@ -358,7 +358,7 @@ UInt32 timer_60 = 0;
 int UPeriod = 0;
 // Number of frame to skip
 
-static int BaseClock;
+int BaseClock;
 
 UChar video_driver = 0;
 /* 0 => Normal driver, normal display
