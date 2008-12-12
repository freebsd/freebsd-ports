--- src/libzrtpcpp/ZrtpPacketBase.h	2008-12-10 14:30:18.000000000 -0500
+++ src/libzrtpcpp/ZrtpPacketBase.h	2008-12-10 14:30:38.000000000 -0500
@@ -26,6 +26,7 @@
 #include <stdint.h>
 #include <string.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 
 #include <libzrtpcpp/zrtpPacket.h>
