--- include/iprt/string.h.orig	2015-10-15 11:50:51 UTC
+++ include/iprt/string.h
@@ -107,7 +107,7 @@ char *strpbrk(const char *pszStr, const 
 RT_C_DECLS_END
 #endif
 
-#if !defined(RT_OS_LINUX) || !defined(_GNU_SOURCE)
+#if !defined(RT_OS_FREEBSD) && (!defined(RT_OS_LINUX) || !defined(_GNU_SOURCE))
 RT_C_DECLS_BEGIN
 void *memrchr(const char *pv, int ch, size_t cb);
 RT_C_DECLS_END
