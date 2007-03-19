--- Src/DasherCore/TimeSpan.cpp.orig	Sun Dec  3 09:50:34 2006
+++ Src/DasherCore/TimeSpan.cpp	Sun Dec  3 18:47:02 2006
@@ -122,7 +122,7 @@ string CTimeSpan::GetTimeStamp()
     szTimeLine = ctime(&(sTimeBuffer.time));
 #else
     gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-    szTimeLine = ctime(&(sTimeBuffer.tv_sec));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 #endif
   
   if ((szTimeLine != NULL) && (strlen(szTimeLine) > 18))
@@ -196,7 +196,7 @@ string CTimeSpan::GetDateStamp()
     szTimeLine = ctime(&(sTimeBuffer.time));
 #else
     gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-    szTimeLine = ctime(&(sTimeBuffer.tv_sec));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 #endif
 
  
