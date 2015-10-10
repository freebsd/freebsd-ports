--- vio/viosocket.c.orig	2015-07-08 07:38:39 UTC
+++ vio/viosocket.c
@@ -33,6 +33,10 @@
 static void (*before_io_wait)(void)= 0;
 static void (*after_io_wait)(void)= 0;
 
+#ifdef __FreeBSD__
+#define s6_addr32 __u6_addr.__u6_addr32
+#endif
+
 /* Wait callback macros (both performance schema and threadpool */
 #define START_SOCKET_WAIT(locker, state_ptr, sock, which, timeout) \
 do                                                                 \
