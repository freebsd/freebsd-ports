--- Src/DasherCore/FileLogger.cpp.orig	Fri Apr 21 17:41:01 2006
+++ Src/DasherCore/FileLogger.cpp	Sun Jun 11 07:33:19 2006
@@ -511,7 +511,7 @@
     szTimeLine = ctime(&(sTimeBuffer.time));
 #else
     gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-    szTimeLine = ctime(&(sTimeBuffer.tv_sec));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 #endif
  
     // Format is:
@@ -538,7 +538,7 @@
 #ifdef _WIN32
         sprintf(strMs, "%d", sTimeBuffer.millitm);
 #else
-        sprintf(strMs, "%d", sTimeBuffer.tv_usec / 1000);
+        sprintf(strMs, "%d", (int) (sTimeBuffer.tv_usec / 1000));
 #endif
         if (strlen(strMs) == 1)
           strTimeStamp += "00";
