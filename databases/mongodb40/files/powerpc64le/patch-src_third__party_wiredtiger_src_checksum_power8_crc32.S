--- src/third_party/wiredtiger/src/checksum/power8/crc32.S.orig	2020-09-02 06:34:58 UTC
+++ src/third_party/wiredtiger/src/checksum/power8/crc32.S
@@ -26,7 +26,11 @@
  * as published by the Free Software Foundation; either version
  * 2 of the License, or (at your option) any later version.
  */
+#ifdef __clang__
+#include "ppc-asm.h"
+#else
 #include <ppc-asm.h>
+#endif
 #include "ppc-opcode.h"
 
 #undef toc
