--- groups/bdl/bdls/bdls_filesystemutil_unixplatform.h.orig	2023-08-03 21:56:56 UTC
+++ groups/bdl/bdls/bdls_filesystemutil_unixplatform.h
@@ -322,7 +322,7 @@ BSLS_IDENT("$Id: $")
 
 #if defined(BSLS_PLATFORM_OS_SOLARIS) ||                          \
     defined(BSLS_PLATFORM_OS_AIX) ||                              \
-    defined(BSLS_PLATFORM_OS_LINUX)
+    defined(BSLS_PLATFORM_OS_LINUX) || defined(BSLS_PLATFORM_OS_FREEBSD)
 
    #define BDLS_FILESYSTEMUTIL_UNIXPLATFORM_STAT_NS_MEMBER st_mtim.tv_nsec
 
