--- plugins/builtin/source/content/providers/disk_provider.cpp.orig	2022-03-03 13:32:30 UTC
+++ plugins/builtin/source/content/providers/disk_provider.cpp
@@ -17,7 +17,9 @@
     #include <sys/stat.h>
     #include <sys/types.h>
 
+# if !defined(__FreeBSD__)
     #define lseek lseek64
+# endif
 #elif defined(OS_MACOS)
     #include <fcntl.h>
     #include <unistd.h>
