--- net.c.orig	2001-12-15 20:51:50.000000000 +0300
+++ net.c	2013-11-17 11:19:18.535476607 +0400
@@ -78,12 +78,16 @@
 {
 	unsigned char *p;
 	int retval;
-	unsigned long crc;
+	unsigned int crc;
 	int s,r;
 	
 	p=mem_alloc(max_len+12);
 	if (!p)return -1;  /* not enough memory */
 	retval=recvfrom(fd,p,max_len+12,0,addr,addr_len);
+	if (retval<12) {
+		mem_free(p);
+		return -1;
+	}
 	memcpy(packet,p+12,max_len);
 	crc=p[0]+(p[1]<<8)+(p[2]<<16)+(p[3]<<24);
 	s=p[4]+(p[5]<<8)+(p[6]<<16)+(p[7]<<24);
