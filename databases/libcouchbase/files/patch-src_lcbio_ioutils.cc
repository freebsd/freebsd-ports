--- src/lcbio/ioutils.cc.orig	2022-12-09 14:14:27 UTC
+++ src/lcbio/ioutils.cc
@@ -24,6 +24,9 @@
 #include "hostlist.h"
 #include "iotable.h"
 #include "ssl.h"
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 
 lcbio_CSERR lcbio_mkcserr(int syserr)
 {
