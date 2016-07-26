--- macunpack/dd.h.orig	1993-10-02 20:16:00 UTC
+++ macunpack/dd.h
@@ -52,7 +52,7 @@
 
 typedef long OSType;
 
-typedef struct fileHdr {		/* 124 bytes */
+struct fileHdr {		/* 124 bytes */
 	unsigned char	magic[4];	/* "DDAR" */
 	unsigned char	fill1[4];	/* ??? */
 	unsigned char	fName[64];	/* a STR63 */
@@ -73,7 +73,7 @@ typedef struct fileHdr {		/* 124 bytes *
 	unsigned short	hdrcrc;		/* true crc */
 };
 
-typedef struct fileCHdr {		/* 84 bytes */
+struct fileCHdr {		/* 84 bytes */
 	unsigned char	magic[4];	/* "\253\315\000\124" */
 	unsigned long	dataLength;	/* lengths */
 	unsigned long	dataCLength;
