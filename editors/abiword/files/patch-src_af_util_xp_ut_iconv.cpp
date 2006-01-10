--- src/af/util/xp/ut_iconv.cpp.orig	Tue Jan 10 00:18:13 2006
+++ src/af/util/xp/ut_iconv.cpp	Tue Jan 10 00:18:31 2006
@@ -67,7 +67,7 @@
 #if defined (WIN32) || defined(__QNXNTO__) || defined(__CYGWIN__) ||  \
 (defined (__MACH__) && defined (__APPLE__)) || \
 (defined(TARGET_OS_MAC) && TARGET_OS_MAC) || \
-defined (__AIX__) || defined(__OpenBSD__) || \
+defined (__AIX__) || defined(__OpenBSD__) || defined (__FreeBSD__) || \
 (defined(__linux__) && defined(__powerpc__) && (__GLIBC__ <= 2) && (__GLIBC_MINOR__ <= 1))
 
 #define ICONV_CONST const
