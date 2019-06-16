Obtained from:	https://github.com/tarantool/tarantool/commit/67d33761ceaf07564a156dc8252b5edb857808ed

--- src/lib/swim/swim_proto.h.orig	2019-04-05 11:27:32 UTC
+++ src/lib/swim/swim_proto.h
@@ -33,6 +33,8 @@
 #include "trivia/util.h"
 #include "uuid/tt_uuid.h"
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #include <stdbool.h>
 
 /**
