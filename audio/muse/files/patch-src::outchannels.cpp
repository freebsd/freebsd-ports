--- src/outchannels.cpp.orig	Thu Apr 15 22:12:15 2004
+++ src/outchannels.cpp	Mon Apr 19 22:37:58 2004
@@ -24,11 +24,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
