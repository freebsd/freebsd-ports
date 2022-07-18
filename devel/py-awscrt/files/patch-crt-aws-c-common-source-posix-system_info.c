--- crt/aws-c-common/source/posix/system_info.c.orig	2022-07-12 00:42:37 UTC
+++ crt/aws-c-common/source/posix/system_info.c
@@ -15,7 +15,9 @@
 #endif
 
 #if defined(__linux__) || defined(__unix__)
+#    if !defined(__FreeBSD__)
 #    include <sys/sysinfo.h>
+#    endif
 #    include <sys/types.h>
 #endif
 
