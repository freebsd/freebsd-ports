--- src/channel/abis/ipa_stream_server.c.orig	2015-02-16 17:09:48.000000000 +0200
+++ src/channel/abis/ipa_stream_server.c	2015-02-16 17:08:09.000000000 +0200
@@ -1,4 +1,5 @@
 #include <stdlib.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <sys/socket.h>
