--- jdk/src/solaris/native/java/net/bsd_close.c
+++ jdk/src/solaris/native/java/net/bsd_close.c
@@ -316,11 +316,8 @@
 }
 
 int NET_Accept(int s, struct sockaddr *addr, int *addrlen) {
-    socklen_t len = *addrlen;
-    int error = accept(s, addr, &len);
-    if (error != -1)
-        *addrlen = (int)len;
-    BLOCKING_IO_RETURN_INT( s, error );
+    /* See NET_RecvFrom() */
+    BLOCKING_IO_RETURN_INT( s, accept(s, addr, (socklen_t *)addrlen) );
 }
 
 int NET_Connect(int s, struct sockaddr *addr, int addrlen) {
