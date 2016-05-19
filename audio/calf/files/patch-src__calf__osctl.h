--- src/calf/osctl.h.orig	2014-01-26 21:24:40 UTC
+++ src/calf/osctl.h
@@ -26,7 +26,10 @@
 #include <vector>
 #include <string.h>
 #include <errno.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>
 #include <iostream>
 
