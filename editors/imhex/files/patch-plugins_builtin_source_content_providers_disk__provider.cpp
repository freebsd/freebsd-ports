--- plugins/builtin/source/content/providers/disk_provider.cpp.orig	2022-08-14 12:54:20 UTC
+++ plugins/builtin/source/content/providers/disk_provider.cpp
@@ -18,8 +18,9 @@
     #include <sys/stat.h>
     #include <sys/types.h>
 
+# if !defined(__FreeBSD__)
     #define lseek lseek64
-
+# endif
 #elif defined(OS_MACOS)
 
     #include <fcntl.h>
