--- Src/DasherCore/FileLogger.cpp.orig	Sun Dec  3 09:50:34 2006
+++ Src/DasherCore/FileLogger.cpp	Sun Dec  3 18:45:55 2006
@@ -511,7 +511,7 @@ std::string CFileLogger::GetTimeDateStam
     szTimeLine = ctime(&(sTimeBuffer.time));
 #else
     gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-    szTimeLine = ctime(&(sTimeBuffer.tv_sec));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 #endif
  
     // Format is:
