--- src/sockaddr_str.c.orig	2019-05-22 09:18:33 UTC
+++ src/sockaddr_str.c
@@ -38,6 +38,8 @@
 #include <osmocom/core/utils.h>
 #include <osmocom/core/byteswap.h>
 
+#include <sys/socket.h>
+
 /*! \addtogroup sockaddr_str
  *
  * Common operations to store IP address as a char string along with a uint16_t port number.
