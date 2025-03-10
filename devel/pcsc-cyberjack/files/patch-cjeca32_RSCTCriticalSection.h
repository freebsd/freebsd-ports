--- cjeca32/RSCTCriticalSection.h.orig	2024-10-06 15:04:53 UTC
+++ cjeca32/RSCTCriticalSection.h
@@ -1,27 +1,27 @@
 #ifndef ECA_RSCTCRITICAL_H
 #define ECA_RSCTCRITICAL_H
-
-#ifdef _WINDOWS
-#include <windows.h>
-#endif
-
-class CJECA32_PRIVATE_CLASS CRSCTCriticalSection
-{
-public:
-	CRSCTCriticalSection(void);
-public:
-	virtual ~CRSCTCriticalSection(void);
-protected:
-#ifdef _WINDOWS
-	CRITICAL_SECTION m_hCritSec;
-#elif defined(OS_LINUX)
-#elif defined(OS_DARWIN)
-//	MPCriticalRegionID	m_CriticalRegionID;
-#endif
-public:
-	void Enter(void);
-public:
-	void Leave(void);
-};
+
+#ifdef _WINDOWS
+#include <windows.h>
+#endif
+
+class CJECA32_PRIVATE_CLASS CRSCTCriticalSection
+{
+public:
+	CRSCTCriticalSection(void);
+public:
+	virtual ~CRSCTCriticalSection(void);
+protected:
+#ifdef _WINDOWS
+	CRITICAL_SECTION m_hCritSec;
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
+#elif defined(OS_DARWIN)
+//	MPCriticalRegionID	m_CriticalRegionID;
+#endif
+public:
+	void Enter(void);
+public:
+	void Leave(void);
+};
 
 #endif
