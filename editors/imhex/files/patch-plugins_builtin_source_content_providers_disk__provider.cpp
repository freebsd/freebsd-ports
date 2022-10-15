--- plugins/builtin/source/content/providers/disk_provider.cpp.orig	2022-10-08 08:03:47 UTC
+++ plugins/builtin/source/content/providers/disk_provider.cpp
@@ -20,7 +20,7 @@
     #include <sys/types.h>
 #endif
 
-#if defined(OS_LINUX)
+#if !defined(__FreeBSD__)
     #define lseek lseek64
 #endif
 
