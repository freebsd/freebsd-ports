--- src/af/util/xp/ut_iconv.cpp.orig	Wed Jul 20 22:24:55 2005
+++ src/af/util/xp/ut_iconv.cpp	Wed Jul 20 22:25:23 2005
@@ -67,7 +67,7 @@
 #if defined (WIN32) || defined(__QNXNTO__) || defined(__CYGWIN__) ||  \
 (defined (__MACH__) && defined (__APPLE__)) || \
 (defined(TARGET_OS_MAC) && TARGET_OS_MAC) || \
-defined (__AIX__) || \
+defined (__AIX__) || defined (__FreeBSD__) || \
 (defined(__linux__) && defined(__powerpc__) && (__GLIBC__ <= 2) && (__GLIBC_MINOR__ <= 1))
 
 #define ICONV_CONST const
