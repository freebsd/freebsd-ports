--- groups/bsl/bsls/bsls_platform.h.orig	2023-04-21 15:40:03 UTC
+++ groups/bsl/bsls/bsls_platform.h
@@ -662,9 +662,16 @@ struct bsls_Platform_Assert;
 
 // GNU libc or Linux or Cygwin
 #if defined(BSLS_PLATFORM_OS_LINUX) || defined(BSLS_PLATFORM_OS_CYGWIN)       \
-    || defined(__GLIBC__)
+    || defined(__GLIBC__) || defined(BSLS_PLATFORM_OS_FREEBSD)
 
+#if defined(BSLS_PLATFORM_OS_FREEBSD)
+    #include <osreldate.h>
+#if __FreeBSD_version < 1300000
+    #include <sys/endian.h>
+#else
     #include <endian.h>
+#endif
+#endif
     #if (__BYTE_ORDER == __LITTLE_ENDIAN)
         #define BSLS_PLATFORM_IS_LITTLE_ENDIAN                                1
     #elif (__BYTE_ORDER == __BIG_ENDIAN)
