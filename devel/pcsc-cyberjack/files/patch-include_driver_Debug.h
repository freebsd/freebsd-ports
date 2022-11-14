--- include/driver/Debug.h.orig	2021-11-03 13:00:16 UTC
+++ include/driver/Debug.h
@@ -42,14 +42,14 @@ class CJECA32_PRIVATE_CLASS CDebug (public)
 public:
 	~CDebug(void);
 
-#if defined(OS_LINUX) || defined(OS_DARWIN)
+#if defined(OS_LINUX) || defined(OS_DARWIN) || defined(OS_FREEBSD)
 	void setLevelMask(unsigned int nLevelMask);
 	void setLogFileName(const char *fname);
 #endif
 	
 private:
    unsigned int m_nLevelMask;
-#if defined(OS_LINUX) || defined(OS_DARWIN)
+#if defined(OS_LINUX) || defined(OS_DARWIN) || defined(OS_FREEBSD)
        char *m_logFileName;
 #endif
 };
