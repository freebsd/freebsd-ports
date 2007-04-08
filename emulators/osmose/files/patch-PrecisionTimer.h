--- ./PrecisionTimer.h.orig	Sat Apr  7 19:48:42 2007
+++ ./PrecisionTimer.h	Sat Apr  7 19:49:31 2007
@@ -81,6 +81,6 @@
         unsigned long long tick_per_second;                  // Self explanatory.
         unsigned long long T0;                               // Self explanatory.
         unsigned long long T1;                               // Self explanatory.
-        double PrecisionTimer::getOneShotDuration();
+        double getOneShotDuration();
 };
 #endif
