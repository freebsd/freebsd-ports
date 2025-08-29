--- src/VBox/Runtime/r3/posix/process-creation-posix.cpp.orig	2025-08-13 19:51:58 UTC
+++ src/VBox/Runtime/r3/posix/process-creation-posix.cpp
@@ -40,7 +40,7 @@
 *********************************************************************************************************************************/
 #define LOG_GROUP RTLOGGROUP_PROCESS
 #include <iprt/cdefs.h>
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
 # define IPRT_WITH_DYNAMIC_CRYPT_R
 #endif
 #if (defined(RT_OS_LINUX) || defined(RT_OS_OS2)) && !defined(_GNU_SOURCE)
@@ -85,7 +85,7 @@
 # include <xlocale.h> /* for newlocale() */
 #endif
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_OS2)
+#if defined(RT_OS_LINUX) || defined(RT_OS_OS2) || defined(RT_OS_FREEBSD)
 /* While Solaris has posix_spawn() of course we don't want to use it as
  * we need to have the child in a different process contract, no matter
  * whether it is started detached or not. */
@@ -174,7 +174,7 @@
 #  define IPRT_LIBPAM_FILE_3            "libpam.1.dylib"
 #  define IPRT_LIBPAM_FILE_3_FIRST_VER 0
 #  define IPRT_LIBPAM_FILE_3_END_VER   0
-# elif RT_OS_LINUX
+# elif RT_OS_LINUX || RT_OS_FREEBSD
 #  define IPRT_LIBPAM_FILE_1           "libpam.so.0"
 #  define IPRT_LIBPAM_FILE_1_FIRST_VER 0
 #  define IPRT_LIBPAM_FILE_1_END_VER   0
@@ -681,7 +681,7 @@ static int rtCheckCredentials(const char *pszUser, con
     if (pPw->pw_passwd && *pPw->pw_passwd)
 # endif
     {
-# if defined(RT_OS_LINUX) || defined(RT_OS_OS2)
+# if defined(RT_OS_LINUX) || defined(RT_OS_OS2) || defined(RT_OS_FREEBSD)
 #  ifdef IPRT_WITH_DYNAMIC_CRYPT_R
         size_t const       cbCryptData = RT_MAX(sizeof(struct crypt_data) * 2, _256K);
 #  else
