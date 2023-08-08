--- plugins/builtin/source/content/providers/disk_provider.cpp.orig	2023-04-04 10:04:22 UTC
+++ plugins/builtin/source/content/providers/disk_provider.cpp
@@ -24,7 +24,7 @@
     #include <sys/types.h>
 #endif
 
-#if defined(OS_LINUX)
+#if !defined(__FreeBSD__)
     #define lseek lseek64
 #endif
 
