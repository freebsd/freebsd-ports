--- include/iprt/string.h.orig	2010-04-28 01:02:16.000000000 +0200
+++ include/iprt/string.h	2010-06-17 16:20:14.000000000 +0200
@@ -60,7 +60,6 @@
 #if    (defined(RT_OS_DARWIN) && defined(KERNEL)) \
     || (defined(RT_OS_FREEBSD) && defined(_KERNEL))
 RT_C_DECLS_BEGIN
-void *memchr(const void *pv, int ch, size_t cb);
 char *strpbrk(const char *pszStr, const char *pszChars);
 RT_C_DECLS_END
 #endif
