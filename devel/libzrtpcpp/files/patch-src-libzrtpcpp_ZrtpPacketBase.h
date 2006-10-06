--- src/libzrtpcpp/ZrtpPacketBase.h	Fri Oct  6 13:49:31 2006
+++ src/libzrtpcpp/ZrtpPacketBase.h	Fri Oct  6 13:49:55 2006
@@ -27,6 +27,7 @@
 #include <stdint.h>
 #include <string.h>
 #include <malloc.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 
 #include <libzrtpcpp/zrtpPacket.h>
