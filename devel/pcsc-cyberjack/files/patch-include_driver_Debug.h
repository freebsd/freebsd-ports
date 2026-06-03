--- include/driver/Debug.h.orig	2026-04-18 11:10:29 UTC
+++ include/driver/Debug.h
@@ -47,7 +47,7 @@ class CJECA32_PRIVATE_CLASS CDebug (public)
 	void SetLoggerCallback(void *p_pcUmdfCallBack);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_DARWIN)
+#if defined(OS_LINUX) || defined(OS_DARWIN) || defined(OS_FREEBSD)
 	void setLevelMask(unsigned int nLevelMask);
 	void setLogFileName(const char *fname);
 #endif
@@ -56,7 +56,7 @@ class CJECA32_PRIVATE_CLASS CDebug (public)
    unsigned int m_nLevelMask;
    void* m_pcUmdfCallBack_1;
 
-#if defined(OS_LINUX) || defined(OS_DARWIN)
+#if defined(OS_LINUX) || defined(OS_DARWIN) || defined(OS_FREEBSD)
        char *m_logFileName;
 #endif
 };
