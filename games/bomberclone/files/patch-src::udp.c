--- src/udp.c.orig	Mon Apr 28 06:56:46 2003
+++ src/udp.c	Fri May  2 17:30:03 2003
@@ -10,6 +10,7 @@
 #include <fcntl.h>
 #include <sys/types.h>
 #include <time.h>
+#include <sys/time.h>
 #ifdef _WIN32
 #include <winsock.h>
 #else
