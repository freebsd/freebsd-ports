--- src/modules/rtp/rtsp_client.c.orig	2009-07-19 14:38:38.000000000 -0400
+++ src/modules/rtp/rtsp_client.c	2009-07-19 14:39:46.000000000 -0400
@@ -23,6 +23,9 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <fcntl.h>
 #include <stdlib.h>
 #include <string.h>
