--- src/modules/raop/raop-client.c.orig	2017-07-24 23:14:10 UTC
+++ src/modules/raop/raop-client.c
@@ -35,6 +35,10 @@
 #include <sys/filio.h>
 #endif
 
+#ifdef HAVE_NETINET_IN_H
+#include <netinet/in.h>
+#endif
+
 #include <pulse/xmalloc.h>
 #include <pulse/timeval.h>
 #include <pulse/sample.h>
