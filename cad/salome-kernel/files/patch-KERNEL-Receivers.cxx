--- src/Communication/Receivers.cxx.orig	2010-06-03 14:59:24.000000000 +0700
+++ src/Communication/Receivers.cxx	2010-06-03 15:00:16.000000000 +0700
@@ -235,6 +235,7 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <rpc/types.h>
 #include <rpc/xdr.h>
 
 template<class T,int (*myFunc)(XDR*,T*),class CorbaSender,class servForT,class ptrForT>
