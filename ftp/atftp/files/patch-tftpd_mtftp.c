--- tftpd_mtftp.c.orig	2010-10-11 12:45:36.000000000 +0800
+++ tftpd_mtftp.c	2010-10-11 12:46:29.000000000 +0800
@@ -369,6 +369,13 @@
           logger(LOG_ERR, "mtftp: can't open socket");
           pthread_exit(NULL);
      }
+
+     int one = 1; 
+     if (setsockopt(sockfd, IPPROTO_IP, IP_RECVDSTADDR, &one, sizeof(one)) != 0)
+     {
+	  logger(LOG_WARNING, "Failed to set socket option: %s",
+		 strerror(errno));
+     }
      /* bind the socket to the tftp port  */
      if (bind(sockfd, (struct sockaddr*)&sa, sizeof(sa)) < 0)
      {
@@ -389,7 +396,8 @@
                   that file name */
                memset(&sa, 0, sizeof(sa)); /* this will hold the client info */
                data_size = data->data_buffer_size;
-               retval = tftp_get_packet(sockfd, -1, NULL, &sa, NULL, NULL,
+               struct sockaddr_in toaddr;
+	       retval = tftp_get_packet(sockfd, -1, NULL, &sa, NULL, &toaddr,
                                         data->timeout,
                                         &data_size, data->data_buffer);
 
@@ -472,8 +480,11 @@
                getsockname(thread->sockfd, (struct sockaddr *)&(sa), &len);
 
                /* configure multicast socket */
-               thread->mcastaddr.imr_multiaddr.s_addr = thread->sa_mcast.sin_addr.s_addr;
-               thread->mcastaddr.imr_interface.s_addr = htonl(INADDR_ANY);
+               thread->mcastaddr.imr_interface.s_addr = toaddr.sin_addr.s_addr;
+               setsockopt(thread->sockfd, IPPROTO_IP, IP_MULTICAST_IF,
+                          &(thread->mcastaddr.imr_interface.s_addr),
+                          sizeof(thread->mcastaddr.imr_interface.s_addr));
+
                setsockopt(thread->sockfd, IPPROTO_IP, IP_MULTICAST_TTL,
                           &data->mcast_ttl, sizeof(data->mcast_ttl));
 
