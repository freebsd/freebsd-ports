--- cjeca32/RSCTCriticalSection.cpp.orig	2021-11-03 13:00:16 UTC
+++ cjeca32/RSCTCriticalSection.cpp
@@ -22,7 +22,7 @@ void CRSCTCriticalSection::Leave(void)
 	LeaveCriticalSection(&m_hCritSec);
 }
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 
 CRSCTCriticalSection::CRSCTCriticalSection(void){
 }
