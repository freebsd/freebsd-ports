--- src/input/librtsp/rtsp_session.c.orig	Sun Jan  5 19:33:57 2003
+++ src/input/librtsp/rtsp_session.c	Sun Jan  5 19:34:29 2003
@@ -22,6 +22,7 @@
  * high level interface to rtsp servers.
  */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netdb.h>
