Obtained from:	https://github.com/tarantool/tarantool/commit/67d33761ceaf07564a156dc8252b5edb857808ed

--- src/lib/swim/swim_proto.c.orig
+++ src/lib/swim/swim_proto.c
@@ -33,6 +33,7 @@
 #include "say.h"
 #include "version.h"
 #include "diag.h"
+#include <sys/socket.h> /* AF_INET for FreeBSD. */
 
 const char *swim_member_status_strs[] = {
 	"alive",
