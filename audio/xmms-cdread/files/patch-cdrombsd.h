--- cdrombsd.h.orig	Sat Aug 18 19:09:10 2001
+++ cdrombsd.h	Sun Mar 23 16:35:33 2003
@@ -9,12 +9,9 @@
 |*| FreeBSD (?) specific code
 \*/
 
-#define GET_LBA(entry) ((entry.addr_type == CD_LBA_FORMAT) ? \
-				ntohl(entry.addr.lba) : \
-					((entry.addr.msf.minute * 60 + \
-					entry.addr.msf.second) * 75 + \
-					entry.addr.msf.frame))
-
+#define GET_LBA(entry) ((entry.addr.msf.minute * 60 \
+			+ entry.addr.msf.second) * 75 \
+			+ entry.addr.msf.frame)
 
 /*\
 |*| Open cdrom device
