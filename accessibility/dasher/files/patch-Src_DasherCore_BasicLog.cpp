--- Src/DasherCore/BasicLog.cpp.orig	Tue Dec  5 22:01:38 2006
+++ Src/DasherCore/BasicLog.cpp	Tue Dec  5 22:02:14 2006
@@ -87,7 +87,7 @@ std::string CBasicLog::GetDateStamp() {
     szTimeLine = ctime(&(sTimeBuffer.time));
 #else
     gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-    szTimeLine = ctime(&(sTimeBuffer.tv_sec));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 #endif
 
     return std::string(szTimeLine).substr(0, 24);
