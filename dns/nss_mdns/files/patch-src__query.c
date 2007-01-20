--- src/query.c.orig	Sun Nov 20 00:56:17 2005
+++ src/query.c	Sat Jan 20 14:34:44 2007
@@ -87,13 +87,36 @@
     if (bind(fd, (struct sockaddr*) &sa, sizeof(sa)) < 0)
         goto fail;
     
+#ifdef IP_PKTINFO
     yes = 1;
-    if (setsockopt(fd, IPPROTO_IP, IP_RECVTTL, &yes, sizeof(yes)) < 0)
-        goto fail;
-
     if (setsockopt(fd, IPPROTO_IP, IP_PKTINFO, &yes, sizeof(yes)) < 0)
         goto fail;
+#else
+    
+#ifdef IP_RECVINTERFACE
+    yes = 1;
+    if (setsockopt (fd, IPPROTO_IP, IP_RECVINTERFACE, &yes, sizeof(yes)) < 0)
+      goto fail;
+#elif defined(IP_RECVIF)
+    yes = 1;
+    if (setsockopt (fd, IPPROTO_IP, IP_RECVIF, &yes, sizeof(yes)) < 0)
+        goto fail;
+#endif
+    
+#ifdef IP_RECVDSTADDR
+    yes = 1;
+    if (setsockopt (fd, IPPROTO_IP, IP_RECVDSTADDR, &yes, sizeof(yes)) < 0)
+        goto fail;
+#endif
+    
+#endif /* IP_PKTINFO */
     
+#ifdef IP_RECVTTL
+    yes = 1;
+    if (setsockopt(fd, IPPROTO_IP, IP_RECVTTL, &yes, sizeof(yes)) < 0)
+        goto fail;
+#endif
+
     if (set_cloexec(fd) < 0)
         goto fail;
     
@@ -113,9 +136,15 @@
     struct sockaddr_in sa;
     struct msghdr msg;
     struct iovec io;
+#ifdef IP_PKTINFO
     struct cmsghdr *cmsg;
+    uint8_t cmsg_data[CMSG_SPACE(sizeof(struct in_pktinfo))];
     struct in_pktinfo *pkti;
-    uint8_t cmsg_data[CMSG_LEN(sizeof(struct in_pktinfo))];
+#elif defined(IP_SENDSRCADDR)
+    struct cmsghdr *cmsg;
+    uint8_t cmsg_data[CMSG_SPACE(sizeof(struct in_addr))];
+    struct in_addr *addr;
+#endif
     int i, n;
     struct ifreq ifreq[32];
     struct ifconf ifconf;
@@ -131,24 +160,43 @@
     io.iov_base = p->data;
     io.iov_len = p->size;
 
-    memset(cmsg_data, 0, sizeof(cmsg_data));
-    cmsg = (struct cmsghdr*) cmsg_data;
-    cmsg->cmsg_len = sizeof(cmsg_data);
-    cmsg->cmsg_level = IPPROTO_IP;
-    cmsg->cmsg_type = IP_PKTINFO;
-
-    pkti = (struct in_pktinfo*) CMSG_DATA(cmsg);
-    pkti->ipi_ifindex = 0;
-    
     memset(&msg, 0, sizeof(msg));
     msg.msg_name = &sa;
     msg.msg_namelen = sizeof(sa);
     msg.msg_iov = &io;
     msg.msg_iovlen = 1;
+    msg.msg_flags = 0;
+
+#ifdef IP_PKTINFO
+    memset(cmsg_data, 0, sizeof(cmsg_data));
     msg.msg_control = cmsg_data;
     msg.msg_controllen = sizeof(cmsg_data);
-    msg.msg_flags = 0;
+	
+    cmsg = CMSG_FIRSTHDR(&msg);
+    cmsg->cmsg_len = CMSG_LEN(sizeof(struct in_pktinfo));
+    cmsg->cmsg_level = IPPROTO_IP;
+    cmsg->cmsg_type = IP_PKTINFO;
+
+    pkti = (struct in_pktinfo*) CMSG_DATA(cmsg);
 
+    msg.msg_controllen = cmsg->cmsg_len;
+#elif defined(IP_SENDSRCADDR)
+    memset(cmsg_data, 0, sizeof(cmsg_data));
+    msg.msg_control = cmsg_data;
+    msg.msg_controllen = sizeof(cmsg_data);
+        
+    cmsg = CMSG_FIRSTHDR(&msg);
+    cmsg->cmsg_len = CMSG_LEN(sizeof(struct in_addr));
+    cmsg->cmsg_level = IPPROTO_IP;
+    cmsg->cmsg_type = IP_SENDSRCADDR;
+	
+    addr = (struct in_addr *)CMSG_DATA(cmsg);
+
+    msg.msg_controllen = cmsg->cmsg_len;
+#elif defined(__GNUC__)
+#warning "FIXME: We need some code to set the outgoing interface/local address here if IP_PKTINFO/IP_SENDSRCADDR is not available"
+#endif
+   
     ifconf.ifc_req = ifreq;
     ifconf.ifc_len = sizeof(ifreq);
     
@@ -183,6 +231,7 @@
         if (ioctl(fd, SIOCGIFINDEX, &ifreq[i]) < 0) 
             continue; /* See above why we ignore this error */
 
+#ifdef IP_PKTINFO
         /* Only send the the packet once per interface. We assume that
          * multiple addresses assigned to the same interface follow
          * immediately one after the other.*/
@@ -190,6 +239,11 @@
             continue;
 
         last_index = pkti->ipi_ifindex = ifreq[i].ifr_ifindex;
+#elif defined(IP_SENDSRCADDR)
+	addr->s_addr = ifsa->sin_addr.s_addr;
+#elif defined(__GNUC__)
+#warning "FIXME: We need some code to set the outgoing interface/local address here if IP_PKTINFO/IP_SENDSRCADDR is not available"
+#endif
         
         for (;;) {
             
@@ -241,7 +295,12 @@
             *ret_ttl = 0;
             
             for (cmsg = CMSG_FIRSTHDR(&msg); cmsg != NULL; cmsg = CMSG_NXTHDR(&msg,cmsg)) {
-                if (cmsg->cmsg_level == SOL_IP && cmsg->cmsg_type == IP_TTL) {
+#ifdef SOL_IP
+                if (cmsg->cmsg_level == SOL_IP && cmsg->cmsg_type == IP_TTL)
+#else
+                if (cmsg->cmsg_level == IPPROTO_IP && cmsg->cmsg_type == IP_TTL)
+#endif
+		{
                     *ret_ttl = (uint8_t) (*(uint32_t*) CMSG_DATA(cmsg));
                     break;
                 }
