--- tools/irsend.c.orig
+++ tools/irsend.c
@@ -40,6 +40,9 @@
 #include <errno.h>
 #include <signal.h>
 #include <limits.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 
 #define PACKET_SIZE 256
 /* three seconds */
