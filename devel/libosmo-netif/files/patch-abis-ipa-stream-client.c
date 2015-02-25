--- src/channel/abis/ipa_stream_client.c.orig	2015-02-16 17:12:17.000000000 +0200
+++ src/channel/abis/ipa_stream_client.c	2015-02-16 17:09:59.000000000 +0200
@@ -1,4 +1,5 @@
 #include <stdlib.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <sys/socket.h>
