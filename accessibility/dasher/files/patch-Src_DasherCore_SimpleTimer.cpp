--- Src/DasherCore/SimpleTimer.cpp.orig	Tue Jan 17 01:43:17 2006
+++ Src/DasherCore/SimpleTimer.cpp	Tue Jan 17 01:46:24 2006
@@ -1,6 +1,6 @@
 #include "SimpleTimer.h"
 
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 // Track memory leaks on Windows to the line that new'd the memory
 #ifdef _WIN32
@@ -14,12 +14,12 @@ static char THIS_FILE[] = __FILE__;
 
 CSimpleTimer::CSimpleTimer()
 {
-  struct timeb sTimeBuffer;
+  struct timeval sTimeBuffer;
 
-  ftime(&sTimeBuffer);
+  gettimeofday(&sTimeBuffer, NULL);
 
-  m_iStartMs       = sTimeBuffer.millitm;
-  m_iStartSecond   = sTimeBuffer.time;
+  m_iStartMs       = (int) (sTimeBuffer.tv_usec / 1000);
+  m_iStartSecond   = (int) sTimeBuffer.tv_sec;
 }
 
 CSimpleTimer::~CSimpleTimer()
@@ -28,12 +28,12 @@ CSimpleTimer::~CSimpleTimer()
 
 double CSimpleTimer::GetElapsed()
 {
-  struct timeb sTimeBuffer;
+  struct timeval sTimeBuffer;
 
-  ftime(&sTimeBuffer);
+  gettimeofday(&sTimeBuffer, NULL);
 
-  int     iEndMs       = sTimeBuffer.millitm;
-  int     iEndSecond   = sTimeBuffer.time;
+  int     iEndMs       = (int) (sTimeBuffer.tv_usec / 1000);
+  int     iEndSecond   = (int) sTimeBuffer.tv_sec;
 
   return  ((double) iEndMs     / 1000.0 + (double) iEndSecond) - 
           ((double) m_iStartMs / 1000.0 + (double) m_iStartSecond);
