--- jdk/src/solaris/native/sun/nio/ch/sctp/SctpChannelImpl.c.org	2018-07-26 09:56:49.897172000 +0200
+++ jdk/src/solaris/native/sun/nio/ch/sctp/SctpChannelImpl.c	2018-07-30 16:13:19.116935000 +0200
@@ -330,11 +330,11 @@
             break;
         case SCTP_ADDR_MADE_PRIM :
             event = sun_nio_ch_sctp_PeerAddrChange_SCTP_ADDR_MADE_PRIM;
-#ifdef __linux__  /* Solaris currently doesn't support SCTP_ADDR_CONFIRMED */
+#ifndef __solaris__  /* Solaris currently doesn't support SCTP_ADDR_CONFIRMED */
             break;
         case SCTP_ADDR_CONFIRMED :
             event = sun_nio_ch_sctp_PeerAddrChange_SCTP_ADDR_CONFIRMED;
-#endif  /* __linux__ */
+#endif  /* __solaris__ */
     }
 
     addressObj = SockAddrToInetSocketAddress(env, (struct sockaddr*)&spc->spc_aaddr);
@@ -445,13 +445,13 @@
             } else if (errno == EINTR) {
                 return IOS_INTERRUPTED;
 
-#ifdef __linux__
+#ifndef __solaris__
             } else if (errno == ENOTCONN) {
                 /* ENOTCONN when EOF reached */
                 rv = 0;
                 /* there will be no control data */
                 msg->msg_controllen = 0;
-#endif /* __linux__ */
+#endif /* __solaris__ */
 
             } else {
                 handleSocketError(env, errno);
@@ -568,7 +568,7 @@
     /* Set up the msghdr structure for sending */
     memset(msg, 0, sizeof (*msg));
     memset(cbuf, 0, cbuf_size);
-    msg->msg_name = &sa;
+    msg->msg_name = (sa_len == 0 ? NULL : &sa);
     msg->msg_namelen = sa_len;
     iov->iov_base = addr;
     iov->iov_len = length;
