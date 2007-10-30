--- util/hash.c.orig	2007-10-30 11:34:44.000000000 +0100
+++ util/hash.c	2007-10-30 11:39:58.000000000 +0100
@@ -29,8 +29,12 @@
 {
 	unsigned	crc = CRC_INIT;
 
-	while (length--)
-		crc = table[(crc ^ *((unsigned char *) bytes)++) & 0xFF] ^ (crc >> 8);
+	unsigned char byte;
+	unsigned len = 0;
+	for(len=0; len<length; len++){
+	byte = ((unsigned char *)bytes)[len];
+	crc = table[(crc ^ byte) & 0xFF] ^ (crc >> 8);
+	}
 	return(crc ^ CRC_FINAL);
 }
 
