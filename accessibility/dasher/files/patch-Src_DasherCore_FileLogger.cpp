--- Src/DasherCore/FileLogger.cpp.orig	Tue Jan 17 01:41:44 2006
+++ Src/DasherCore/FileLogger.cpp	Tue Jan 17 01:51:33 2006
@@ -17,7 +17,7 @@ static char THIS_FILE[] = __FILE__;
 #include <windows.h>
 #endif
 
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 CFileLogger::CFileLogger(const std::string& strFilenamePath, eLogLevel iLogLevel, int iOptionsMask)
 {
@@ -492,12 +492,12 @@ std::string CFileLogger::GetTimeDateStam
 
   if ((m_bTimeStamp) || (m_bDateStamp))
   {
-    struct timeb sTimeBuffer;
+    struct timeval sTimeBuffer;
     char* szTimeLine = NULL;
 
-    ftime(&sTimeBuffer);
+    gettimeofday(&sTimeBuffer, NULL);
 
-    szTimeLine = ctime(&(sTimeBuffer.time));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 
     // Format is:
     // Wed Jun 22 10:22:00 2005
@@ -520,7 +520,7 @@ std::string CFileLogger::GetTimeDateStam
           strTimeStamp += szTimeLine[i];
         strTimeStamp += ".";
         char strMs[16];
-        sprintf(strMs, "%d", sTimeBuffer.millitm);
+        sprintf(strMs, "%d", (int) (sTimeBuffer.tv_usec / 1000));
         if (strlen(strMs) == 1)
           strTimeStamp += "00";
         else if (strlen(strMs) == 2)
