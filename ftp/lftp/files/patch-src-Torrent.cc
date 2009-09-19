--- src/Torrent.cc.orig	2009-09-16 18:02:13.808225067 +0000
+++ src/Torrent.cc	2009-09-16 18:02:27.236576994 +0000
@@ -24,6 +24,7 @@
 #include <stdlib.h>
 #include <assert.h>
 #include <sys/socket.h>
+#include <sys/stat.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
