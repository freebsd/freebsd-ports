--- iputils.hh.orig	2016-02-05 09:35:08 UTC
+++ iputils.hh
@@ -79,6 +79,11 @@
 
 #endif
 
+// for FreeBSD
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#endif
+
 union ComboAddress {
   struct sockaddr_in sin4;
   struct sockaddr_in6 sin6;
