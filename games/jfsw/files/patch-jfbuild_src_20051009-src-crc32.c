--- jfbuild_src_20051009/src/crc32.c.orig	2005-10-09 15:23:00.000000000 +0200
+++ jfbuild_src_20051009/src/crc32.c	2005-10-10 15:06:18.000000000 +0200
@@ -73,16 +73,6 @@
 	}
 }
 
-
-unsigned long crc32(unsigned char *blk, unsigned long len)
-{
-	unsigned long crc;
-	
-	crc32init(&crc);
-	crc32block(&crc, blk, len);
-	return crc32finish(&crc);
-}
-
 void crc32init(unsigned long *crcvar)
 {
 	if (!crcvar) return;
