$FreeBSD$

--- send_packets.c.orig
+++ send_packets.c
@@ -45,7 +45,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <netinet/udp.h>
-#if defined(__DARWIN) || defined(__CYGWIN)
+#if defined(__DARWIN) || defined(__CYGWIN) || defined(__FreeBSD__)
 #include <netinet/in.h>
 #endif
 #ifndef __CYGWIN
