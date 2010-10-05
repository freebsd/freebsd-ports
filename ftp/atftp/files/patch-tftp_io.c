--- tftp_io.c.orig	2004-02-19 09:30:00.000000000 +0800
+++ tftp_io.c	2010-10-04 18:45:56.000000000 +0800
@@ -102,8 +102,8 @@
      tftphdr.th_opcode = htons(ACK);
      tftphdr.th_block = htons(block_number);
 
-     result = sendto(socket, &tftphdr, 4, 0, (struct sockaddr *)sa,
-                     sizeof(*sa));
+     result = write(socket, &tftphdr, 4);
+
      if (result < 0)
           return ERR;
      return OK;
@@ -141,8 +141,8 @@
           }
      }
      /* send the buffer */
-     result = sendto(socket, buffer, index, 0, (struct sockaddr *)sa,
-                     sizeof(*sa));
+     result = write(socket, buffer, index);
+
      if (result < 0)
           return ERR;
      return OK;
@@ -191,8 +191,8 @@
      tftphdr->th_opcode = htons(DATA);
      tftphdr->th_block = htons(block_number);
 
-     result = sendto(socket, data, size, 0, (struct sockaddr *)sa,
-                     sizeof(*sa));
+     result = write(socket, data, size);
+
      if (result < 0)
           return ERR;
      return OK;
@@ -214,7 +214,6 @@
 
      struct msghdr msg;         /* used to get client's packet info */
      struct cmsghdr *cmsg;
-     struct in_pktinfo *pktinfo;
      struct iovec iov;
      char cbuf[1024];
 
@@ -284,11 +283,12 @@
                     cmsg != NULL && cmsg->cmsg_len >= sizeof(*cmsg);
                     cmsg = CMSG_NXTHDR(&msg, cmsg))
                {
-                    if (cmsg->cmsg_level == SOL_IP
-                        && cmsg->cmsg_type == IP_PKTINFO)
+                    if (cmsg->cmsg_level == IPPROTO_IP
+		        && cmsg->cmsg_type == IP_RECVDSTADDR)
                     {
-                         pktinfo = (struct in_pktinfo *)CMSG_DATA(cmsg);
-                         sa_to->sin_addr = pktinfo->ipi_addr;
+			 struct in_addr *pktinfo;
+			 pktinfo = (struct in_addr *)CMSG_DATA(cmsg);
+			 sa_to->sin_addr = *pktinfo;
                     }
                     break;
                }
