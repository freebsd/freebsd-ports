--- examples/rs232-write.c.orig	2015-02-23 11:51:17 UTC
+++ examples/rs232-write.c
@@ -3,6 +3,7 @@
 #include <string.h>
 #include <arpa/inet.h>
 #include <unistd.h>
+#include <endian.h>
 
 #include <osmocom/core/select.h>
 #include <osmocom/core/talloc.h>
