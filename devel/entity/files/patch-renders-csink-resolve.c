--- renderers/csink/resolve.c.old      Wed Mar 14 20:40:09 2001
+++ renderers/csink/resolve.c  Fri Apr  6 11:16:29 2001
@@ -1,6 +1,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
