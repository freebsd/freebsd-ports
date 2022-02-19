--- plugins/builtin/source/content/providers/disk_provider.cpp.orig	2022-02-15 12:57:57 UTC
+++ plugins/builtin/source/content/providers/disk_provider.cpp
@@ -15,7 +15,9 @@
     #include <sys/stat.h>
     #include <sys/types.h>
 
+# if !defined(__FreeBSD__)
     #define lseek lseek64
+# endif
 #elif defined(OS_MACOS)
     #include <fcntl.h>
     #include <unistd.h>
