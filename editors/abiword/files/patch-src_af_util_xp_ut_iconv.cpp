--- src/af/util/xp/ut_iconv.cpp.orig	Fri Jan  2 16:00:33 2004
+++ src/af/util/xp/ut_iconv.cpp	Fri Jan  2 16:08:03 2004
@@ -67,7 +67,7 @@
 #if defined (WIN32) || defined(__QNXNTO__) || defined(__CYGWIN__) ||  \
 (defined (__MACH__) && defined (__APPLE__)) || \
 (defined(TARGET_OS_MAC) && TARGET_OS_MAC) || \
-defined(__BEOS__) || defined (__AIX__) || \
+defined(__BEOS__) || defined (__AIX__) || defined (__FreeBSD__) || \
 (defined(__linux__) && defined(__powerpc__) && (__GLIBC__ <= 2) && (__GLIBC_MINOR__ <= 1))
 
 #define ICONV_CONST const
