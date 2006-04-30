--- Src/DasherCore/UserLog.cpp.orig	Tue Jan 17 01:49:12 2006
+++ Src/DasherCore/UserLog.cpp	Tue Jan 17 01:50:11 2006
@@ -1,7 +1,7 @@
 
 #include "UserLog.h"
 #include <fstream>
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 // Track memory leaks on Windows to the line that new'd the memory
 #ifdef _WIN32
@@ -624,12 +624,12 @@ void CUserLog::SetOuputFilename(const st
   {
     m_strFilename = USER_LOG_DETAILED_PREFIX;
 
-    struct timeb sTimeBuffer;
+    struct timeval sTimeBuffer;
     char* szTimeLine = NULL;
 
-    ftime(&sTimeBuffer);
+    gettimeofday(&sTimeBuffer, NULL);
 
-    szTimeLine = ctime(&(sTimeBuffer.time));
+    szTimeLine = ctime((const time_t *)&(sTimeBuffer.tv_sec));
 
     if ((szTimeLine != NULL) && (strlen(szTimeLine) > 18))
     {
@@ -829,10 +829,10 @@ bool CUserLog::UpdateMouseLocation()
 {
   //CFunctionLogger f1("CUserLog::UpdateMouseLocation", g_pLogger);
 
-  struct timeb sTimeBuffer;
-  ftime(&sTimeBuffer);
+  struct timeval sTimeBuffer;
+  gettimeofday(&sTimeBuffer, NULL);
 
-  double dTime = (sTimeBuffer.time * 1000.0) + sTimeBuffer.millitm;
+  double dTime = (sTimeBuffer.tv_sec * 1000.0) + (int) (sTimeBuffer.tv_usec / 1000);
 
   if ((dTime - m_dLastMouseUpdate) > LOG_MOUSE_EVERY_MS)
   {
