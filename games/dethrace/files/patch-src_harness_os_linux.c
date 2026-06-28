--- src/harness/os/linux.c.orig	2026-06-28 21:37:35 UTC
+++ src/harness/os/linux.c
@@ -32,6 +32,7 @@
 #include <termios.h>
 #include <time.h>
 #include <unistd.h>
+#include <netinet/in.h>
 
 #if SUPPORT_TRACEBACK
 #include <execinfo.h>
