--- pce.c.orig	2005-03-28 08:17:45.000000000 -0600
+++ pce.c	2007-10-09 21:32:50.000000000 -0500
@@ -358,7 +358,7 @@
 int UPeriod = 0;
 // Number of frame to skip
 
-static int BaseClock;
+int BaseClock;
 
 UChar video_driver = 0;
 /* 0 => Normal driver, normal display
