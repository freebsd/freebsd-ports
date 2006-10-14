--- Src/DasherCore/TimeSpan.cpp.orig	Fri Apr 21 17:41:02 2006
+++ Src/DasherCore/TimeSpan.cpp	Sun Jun 11 09:21:30 2006
@@ -122,7 +122,7 @@
     szTimeLine = ctime(&(sTimeBuffer.time));
 #else
     gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-    szTimeLine = ctime(&(sTimeBuffer.tv_sec));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 #endif
   
   if ((szTimeLine != NULL) && (strlen(szTimeLine) > 18))
@@ -134,7 +134,7 @@
 #ifdef _WIN32
     sprintf(szMs, "%d", sTimeBuffer.millitm);
 #else
-    sprintf(szMs, "%d", sTimeBuffer.tv_usec / 1000);
+    sprintf(szMs, "%d", (int) (sTimeBuffer.tv_usec / 1000));
 #endif
     if (strlen(szMs) == 1)
       strTimeStamp += "00";
@@ -196,7 +196,7 @@
     szTimeLine = ctime(&(sTimeBuffer.time));
 #else
     gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-    szTimeLine = ctime(&(sTimeBuffer.tv_sec));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 #endif
 
  
