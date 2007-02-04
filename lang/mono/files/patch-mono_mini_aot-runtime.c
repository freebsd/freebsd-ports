--- mono/mini/aot-runtime.c.orig	Sun Oct 22 13:10:53 2006
+++ mono/mini/aot-runtime.c	Sun Oct 22 13:16:25 2006
@@ -19,6 +19,9 @@
 #include <winsock2.h>
 #include <windows.h>
 #endif
+#ifdef PLATFORM_BSD
+#include <sys/wait.h>
+#endif
 
 #include <errno.h>
 #include <sys/stat.h>
