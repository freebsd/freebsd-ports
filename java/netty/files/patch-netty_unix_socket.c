--- netty_unix_socket.c.orig	2019-09-28 17:55:20.362544000 -0700
+++ netty_unix_socket.c	2019-09-28 17:59:09.282432000 -0700
@@ -389,6 +389,9 @@
     }
 
 #ifdef IP_RECVORIGDSTADDR
+#if defined(__FreeBSD__) && !defined(SOL_IP)
+#define SOL_IP IPPROTO_IP
+#endif /* __FreeBSD__ && !SOL_IP */
     if (readLocalAddr) {
         for (cmsg = CMSG_FIRSTHDR(&msg); cmsg != NULL; cmsg = CMSG_NXTHDR(&msg, cmsg)) {
             if (cmsg->cmsg_level == SOL_IP && cmsg->cmsg_type == IP_RECVORIGDSTADDR) {
