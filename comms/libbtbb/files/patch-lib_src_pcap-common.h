--- lib/src/pcap-common.h.orig	2018-09-03 16:11:15 UTC
+++ lib/src/pcap-common.h
@@ -37,7 +37,7 @@
 #define htole16 EndianU16_NtoL
 #define htole32 EndianU32_NtoL
 #else
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 #if !defined( htole16 ) /* will be defined under Linux when endian.h already included */
