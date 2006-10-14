--- Src/DasherCore/SimpleTimer.cpp.orig	Wed May 31 00:14:12 2006
+++ Src/DasherCore/SimpleTimer.cpp	Wed May 31 00:14:23 2006
@@ -34,8 +34,8 @@ CSimpleTimer::CSimpleTimer()
     m_iStartSecond   = sTimeBuffer.time;
 #else
     gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-    m_iStartMs       = sTimeBuffer.tv_usec / 1000;
-    m_iStartSecond   = sTimeBuffer.tv_sec;
+    m_iStartMs       = (int) sTimeBuffer.tv_usec / 1000;
+    m_iStartSecond   = (int) sTimeBuffer.tv_sec;
 #endif
 
 }
@@ -59,8 +59,8 @@ double CSimpleTimer::GetElapsed()
   int     iEndSecond   = sTimeBuffer.time;
 #else
   gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-  int     iEndMs       = sTimeBuffer.tv_usec / 1000;
-  int     iEndSecond   = sTimeBuffer.tv_sec;
+  int     iEndMs       = (int) sTimeBuffer.tv_usec / 1000;
+  int     iEndSecond   = (int) sTimeBuffer.tv_sec;
 #endif
 
 
