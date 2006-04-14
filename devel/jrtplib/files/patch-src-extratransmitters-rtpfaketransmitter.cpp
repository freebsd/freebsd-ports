--- src/extratransmitters/rtpfaketransmitter.cpp.orig  Fri Apr  7 13:54:07 2006
+++ src/extratransmitters/rtpfaketransmitter.cpp       Fri Apr  7 13:54:25 2006
@@ -51,6 +51,7 @@
 #include "rtptimeutilities.h"
 #include <stdio.h>

+#include <sys/socket.h>
 #include <net/if.h>
 #include <string.h>
 #include <netdb.h>
