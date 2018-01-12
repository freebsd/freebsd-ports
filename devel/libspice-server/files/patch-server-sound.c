--- server/sound.c.orig	2017-09-21 11:05:07 UTC
+++ server/sound.c
@@ -22,6 +22,8 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <limits.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
