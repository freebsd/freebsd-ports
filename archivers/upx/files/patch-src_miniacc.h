--- src/miniacc.h.orig	2013-09-30 15:51:00 UTC
+++ src/miniacc.h
@@ -485,7 +485,7 @@
 #  if defined(_AIX) || defined(__AIX__) || defined(__aix__)
 #    define ACC_OS_POSIX_AIX        1
 #    define ACC_INFO_OS_POSIX       "aix"
-#  elif defined(__FreeBSD__)
+#  elif defined(__FreeBSD__) || defined(__DragonFly__)
 #    define ACC_OS_POSIX_FREEBSD    1
 #    define ACC_INFO_OS_POSIX       "freebsd"
 #  elif defined(__hpux__) || defined(__hpux)
@@ -1968,7 +1968,7 @@ ACC_COMPILE_TIME_ASSERT_HEADER(ACC_SIZEO
 #elif !(ACC_ABI_BIG_ENDIAN) && !(ACC_ABI_LITTLE_ENDIAN)
 #if (ACC_ARCH_ALPHA) && (ACC_ARCH_CRAY_MPP)
 #  define ACC_ABI_BIG_ENDIAN        1
-#elif (ACC_ARCH_IA64) && (ACC_OS_POSIX_LINUX || ACC_OS_WIN64)
+#elif (ACC_ARCH_IA64) && (ACC_OS_POSIX_LINUX || ACC_OS_POSIX_FREEBSD || ACC_OS_WIN64)
 #  define ACC_ABI_LITTLE_ENDIAN     1
 #elif (ACC_ARCH_ALPHA || ACC_ARCH_AMD64 || ACC_ARCH_BLACKFIN || ACC_ARCH_CRIS || ACC_ARCH_I086 || ACC_ARCH_I386 || ACC_ARCH_MSP430)
 #  define ACC_ABI_LITTLE_ENDIAN     1
