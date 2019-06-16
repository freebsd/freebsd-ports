Obtained from:	https://github.com/tarantool/tarantool/commit/67d33761ceaf07564a156dc8252b5edb857808ed
		https://github.com/tarantool/tarantool/commit/03e114b91a55dbb89ea9b0b5f134dd6a19ea6a81

--- src/lib/swim/swim_transport.h.orig	2019-04-05 11:27:32 UTC
+++ src/lib/swim/swim_transport.h
@@ -31,7 +31,9 @@
  * SUCH DAMAGE.
  */
 #include "trivia/util.h"
+#include <netinet/in.h>
 #include <arpa/inet.h>
+#include <unistd.h>
 
 /** Transport implementation. */
 struct swim_transport {
