--- Src/DasherCore/TimeSpan.cpp.orig	Tue Jan 17 01:47:12 2006
+++ Src/DasherCore/TimeSpan.cpp	Tue Jan 17 01:48:47 2006
@@ -1,6 +1,6 @@
 
 #include "TimeSpan.h"
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 #ifdef _WIN32
 // In order to track leaks to line number, we need this at the top of every file
@@ -102,12 +102,12 @@ string CTimeSpan::GetXML(const string& s
 string CTimeSpan::GetTimeStamp()
 {
   string strTimeStamp = "";
-  struct timeb sTimeBuffer;
+  struct timeval sTimeBuffer;
   char* szTimeLine = NULL;
 
-  ftime(&sTimeBuffer);
+  gettimeofday(&sTimeBuffer, NULL);
 
-  szTimeLine = ctime(&(sTimeBuffer.time));
+  szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 
   if ((szTimeLine != NULL) && (strlen(szTimeLine) > 18))
   {
@@ -115,7 +115,7 @@ string CTimeSpan::GetTimeStamp()
       strTimeStamp += szTimeLine[i];
     strTimeStamp += ".";
     char szMs[16];
-    sprintf(szMs, "%d", sTimeBuffer.millitm);
+    sprintf(szMs, "%d", (int) (sTimeBuffer.tv_usec / 1000));
     if (strlen(szMs) == 1)
       strTimeStamp += "00";
     else if (strlen(szMs) == 2)
@@ -163,12 +163,12 @@ string CTimeSpan::GetDateStamp()
 {
   std::string strDateStamp = "";
 
-  struct timeb sTimeBuffer;
+  struct timeval sTimeBuffer;
   char* szTimeLine = NULL;
 
-  ftime(&sTimeBuffer);
+  gettimeofday(&sTimeBuffer, NULL);
 
-  szTimeLine = ctime(&(sTimeBuffer.time));
+  szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 
   // Format is:
   // Wed Jun 22 10:22:00 2005
