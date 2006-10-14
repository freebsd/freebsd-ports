--- Src/DasherCore/UserLog.cpp.orig	Fri Apr 21 17:41:02 2006
+++ Src/DasherCore/UserLog.cpp	Sun Jun 11 10:43:33 2006
@@ -668,7 +668,7 @@
     szTimeLine = ctime(&(sTimeBuffer.time));
 #else
     gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-    szTimeLine = ctime(&(sTimeBuffer.tv_sec));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 #endif
 
     if ((szTimeLine != NULL) && (strlen(szTimeLine) > 18))
@@ -881,7 +881,7 @@
   double dTime = (sTimeBuffer.time * 1000.0) + sTimeBuffer.millitm;
 #else
   gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-  double dTime = (sTimeBuffer.tv_sec * 1000.0) + sTimeBuffer.tv_usec / 1000;
+  double dTime = (sTimeBuffer.tv_sec * 1000.0) + (int) (sTimeBuffer.tv_usec / 1000);
 #endif
 
   
