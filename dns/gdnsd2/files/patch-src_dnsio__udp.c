--- src/dnsio_udp.c.orig	2019-01-16 15:44:43 UTC
+++ src/dnsio_udp.c
@@ -296,13 +296,16 @@ static void mainloop(const int fd, void*
         .iov_len  = 0
     };
     struct msghdr msg_hdr;
-    char cmsg_buf[cmsg_size];
-    memset(cmsg_buf, 0, sizeof(cmsg_buf));
+    union {
+	char cbuf[CMSG_BUFSIZE];
+	struct cmsghdr align;
+    } cmsg_buf;
+    memset(cmsg_buf.cbuf, 0, sizeof(cmsg_buf.cbuf));
     memset(&msg_hdr, 0, sizeof(struct msghdr));
     msg_hdr.msg_name       = &asin.sa;
     msg_hdr.msg_iov        = &iov;
     msg_hdr.msg_iovlen     = 1;
-    msg_hdr.msg_control    = use_cmsg ? cmsg_buf : NULL;
+    msg_hdr.msg_control    = use_cmsg ? cmsg_buf.cbuf : NULL;
 
 #if GDNSD_B_QSBR
     const struct timeval tmout_short = { .tv_sec = 0, .tv_usec = PRCU_DELAY_US };
@@ -341,6 +344,21 @@ static void mainloop(const int fd, void*
         recvmsg_rv = recvmsg(fd, &msg_hdr, 0);
 #endif
 
+#if defined __FreeBSD__ && defined IPV6_PKTINFO
+        if(asin.sa.sa_family == AF_INET6) {
+            struct cmsghdr* cmsg;
+            for(cmsg = (struct cmsghdr *)CMSG_FIRSTHDR(&msg_hdr); cmsg;
+                cmsg = (struct cmsghdr *)CMSG_NXTHDR(&msg_hdr, cmsg)) {
+                if((cmsg->cmsg_level == IPPROTO_IPV6) && (cmsg->cmsg_type == IPV6_PKTINFO)) {
+                    struct in6_pktinfo* pi = (void*)CMSG_DATA((struct cmsghdr*)cmsg_buf.cbuf);
+                    if(!IN6_IS_ADDR_LINKLOCAL(&pi->ipi6_addr))
+                        pi->ipi6_ifindex = 0;
+                    continue;
+                }
+            }
+        }
+#endif
+
         if(unlikely(
                (asin.sa.sa_family == AF_INET && !asin.sin.sin_port)
             || (asin.sa.sa_family == AF_INET6 && !asin.sin6.sin6_port)
