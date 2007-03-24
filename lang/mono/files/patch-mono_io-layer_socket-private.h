--- mono/io-layer/socket-private.h.orig	Thu Jan 25 01:11:18 2007
+++ mono/io-layer/socket-private.h	Sat Mar 24 16:49:54 2007
@@ -20,6 +20,7 @@
 	int domain;
 	int type;
 	int protocol;
+	int saved_error;
 };
 
 #endif /* _WAPI_SOCKET_PRIVATE_H_ */
