--- plugins/builtin/source/content/providers/disk_provider.cpp.orig	2021-12-16 17:57:41 UTC
+++ plugins/builtin/source/content/providers/disk_provider.cpp
@@ -11,7 +11,9 @@
     #include <sys/stat.h>
     #include <sys/types.h>
 
+# if !defined(__FreeBSD__)
     #define lseek lseek64
+# endif
 #elif defined (OS_MACOS)
     #include <fcntl.h>
     #include <unistd.h>
