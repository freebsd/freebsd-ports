--- src/Communication/ReceiverFactory.cxx.orig	2010-06-03 14:59:15.000000000 +0700
+++ src/Communication/ReceiverFactory.cxx	2010-06-03 15:00:38.000000000 +0700
@@ -43,6 +43,7 @@
 #endif
 
 #ifdef HAVE_SOCKET
+#include <rpc/types.h>
 #include <rpc/xdr.h>
 #endif
 
