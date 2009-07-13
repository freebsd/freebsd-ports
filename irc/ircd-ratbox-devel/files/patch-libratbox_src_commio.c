--- ./libratbox/src/commio.c.orig	2009-07-11 18:37:37.000000000 +0100
+++ ./libratbox/src/commio.c	2009-07-11 18:37:55.000000000 +0100
@@ -2156,7 +2156,7 @@
 	if(msg.msg_controllen > 0 && msg.msg_control != NULL
 	   && (cmsg = CMSG_FIRSTHDR(&msg)) != NULL)
 	{
-		rfds = (msg.msg_controllen - sizeof(struct cmsghdr)) / sizeof(int);
+		rfds = ((unsigned char *)cmsg + cmsg->cmsg_len - CMSG_DATA(cmsg)) / sizeof(int);
 
 		for(x = 0; x < nfds && x < rfds; x++)
 		{
