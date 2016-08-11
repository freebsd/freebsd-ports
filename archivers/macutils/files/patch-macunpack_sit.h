--- macunpack/sit.h.orig	1993-10-02 20:16:00 UTC
+++ macunpack/sit.h
@@ -24,7 +24,7 @@
 
 typedef long OSType;
 
-typedef struct sitHdr {			/* 22 bytes */
+struct sitHdr {			/* 22 bytes */
 	OSType	signature;		/* = 'SIT!' -- for verification */
 	unsigned short	numFiles;	/* number of files in archive */
 	unsigned long	arcLength;	/* length of entire archive incl.
@@ -34,7 +34,7 @@ typedef struct sitHdr {			/* 22 bytes */
 	char reserved[7];
 };
 
-typedef struct fileHdr {		/* 112 bytes */
+struct fileHdr {		/* 112 bytes */
 	unsigned char	compRMethod;	/* rsrc fork compression method */
 	unsigned char	compDMethod;	/* data fork compression method */
 	unsigned char	fName[64];	/* a STR63 */
