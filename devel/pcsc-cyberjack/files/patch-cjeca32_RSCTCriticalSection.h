--- cjeca32/RSCTCriticalSection.h.orig	2026-04-18 11:08:45 UTC
+++ cjeca32/RSCTCriticalSection.h
@@ -14,7 +14,7 @@ class CJECA32_PRIVATE_CLASS CRSCTCriticalSection (prot
 protected:
 #ifdef _WINDOWS
 	CRITICAL_SECTION m_hCritSec;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #elif defined(OS_DARWIN)
 //	MPCriticalRegionID	m_CriticalRegionID;
 #endif
