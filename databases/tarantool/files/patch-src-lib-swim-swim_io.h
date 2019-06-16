Obtained from:	https://github.com/tarantool/tarantool/commit/67d33761ceaf07564a156dc8252b5edb857808ed

--- src/lib/swim/swim_io.h.orig
+++ src/lib/swim/swim_io.h
@@ -37,6 +37,7 @@
 #include "tarantool_ev.h"
 #include <stdbool.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 /**
  * SWIM protocol transport level.
