Obtained from:	https://github.com/tarantool/tarantool/commit/67d33761ceaf07564a156dc8252b5edb857808ed

--- test/unit/swim_test_transport.c.orig
+++ test/unit/swim_test_transport.c
@@ -33,6 +33,7 @@
 #include "swim/swim_io.h"
 #include "fiber.h"
 #include <errno.h>
+#include <sys/socket.h>
 
 enum {
 	/**
