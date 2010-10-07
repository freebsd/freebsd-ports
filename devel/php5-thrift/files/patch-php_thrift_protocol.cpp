--- php_thrift_protocol.cpp	2010-04-23 17:28:32.000000000 +0400
+++ php_thrift_protocol.cpp	2010-04-23 17:29:32.000000000 +0400
@@ -24,8 +24,7 @@
 #include <sys/types.h>
 #include <netinet/in.h>
 #include <unistd.h>
-#include <endian.h>
-#include <byteswap.h>
+#include <machine/endian.h>
 #include <stdexcept>
 
 #if __BYTE_ORDER == __LITTLE_ENDIAN
@@ -36,6 +35,7 @@
 #define ntohll(x) x
 #endif
 
+#define bswap_64 __bswap64
 enum TType {
   T_STOP       = 0,
   T_VOID       = 1,
