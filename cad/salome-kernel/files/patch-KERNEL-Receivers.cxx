--- src/Communication/Receivers.cxx.orig	2009-03-18 20:52:29.000000000 +0600
+++ src/Communication/Receivers.cxx	2009-05-20 10:21:06.000000000 +0700
@@ -235,6 +235,7 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <rpc/types.h>
 #include <rpc/xdr.h>
 
 template<class T,int (*myFunc)(XDR*,T*),class CorbaSender,class servForT,class ptrForT>
