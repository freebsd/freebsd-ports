--- qemu/exec.c.orig	Mon Oct 11 00:14:19 2004
+++ qemu/exec.c	Thu Oct 28 23:28:25 2004
@@ -21,6 +21,7 @@
 #ifdef _WIN32
 #include <windows.h>
 #else
+#include <sys/types.h>
 #include <sys/mman.h>
 #endif
 #include <stdlib.h>
