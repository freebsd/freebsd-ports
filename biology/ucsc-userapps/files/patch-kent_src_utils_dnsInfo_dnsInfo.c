--- kent/src/utils/dnsInfo/dnsInfo.c.orig	2021-04-18 01:19:08 UTC
+++ kent/src/utils/dnsInfo/dnsInfo.c
@@ -7,6 +7,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/utsname.h>
+#include <sys/socket.h>
 #include "linefile.h"
 #include "hash.h"
 #include "options.h"
