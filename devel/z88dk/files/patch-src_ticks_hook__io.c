--- src/ticks/hook_io.c.orig	2018-04-26 07:38:01 UTC
+++ src/ticks/hook_io.c
@@ -10,6 +10,8 @@
 #ifdef WIN32
 #include        <io.h>
 #include        <sys/stat.h>
+#elif defined(__FreeBSD__)
+#include        <sys/stat.h>
 #else
 #include        <unistd.h>
 #endif
