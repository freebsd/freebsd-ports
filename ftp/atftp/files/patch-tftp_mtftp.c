--- tftp_mtftp.c.orig	2010-10-05 14:12:47.000000000 +0800
+++ tftp_mtftp.c	2010-10-05 14:13:19.000000000 +0800
@@ -138,7 +138,8 @@
      memset(&file_bitmap, 0, sizeof(file_bitmap));
 
      /* make sure the socket is not connected */
-     sa.sin_family = AF_UNSPEC;
+     memset(&sa, 0, sizeof(sa));
+     sa.sin_family = AF_INET;
      connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
 
      /* copy sa_peer structure */
