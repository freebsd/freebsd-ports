--- outchannels.cpp.orig	Fri Jun  7 02:44:42 2002
+++ outchannels.cpp	Fri Jun  7 02:44:48 2002
@@ -20,11 +20,11 @@
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
