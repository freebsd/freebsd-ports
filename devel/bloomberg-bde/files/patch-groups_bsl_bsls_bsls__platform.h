--- groups/bsl/bsls/bsls_platform.h.orig	2023-07-30 12:59:02 UTC
+++ groups/bsl/bsls/bsls_platform.h
@@ -662,7 +662,7 @@ struct bsls_Platform_Assert;
 
 // GNU libc or Linux or Cygwin
 #if defined(BSLS_PLATFORM_OS_LINUX) || defined(BSLS_PLATFORM_OS_CYGWIN)       \
-    || defined(__GLIBC__)
+    || defined(__GLIBC__) || defined(BSLS_PLATFORM_OS_FREEBSD)
 
     #include <endian.h>
     #if (__BYTE_ORDER == __LITTLE_ENDIAN)
