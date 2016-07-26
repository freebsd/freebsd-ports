--- macunpack/cpt.h.orig	1993-10-02 20:16:00 UTC
+++ macunpack/cpt.h
@@ -31,7 +31,7 @@
 
 typedef long	OSType;
 
-typedef struct cptHdr {			/* 8 bytes */
+struct cptHdr {			/* 8 bytes */
 	unsigned char	signature;	/* = 1 -- for verification */
 	unsigned char	volume;		/* for multi-file archives */
 	unsigned short	xmagic;		/* verification multi-file consistency*/
@@ -42,7 +42,7 @@ typedef struct cptHdr {			/* 8 bytes */
 	unsigned char	commentsize;	/* number of bytes comment that follow*/
 };
 
-typedef struct fileHdr {		/* 78 bytes */
+struct fileHdr {		/* 78 bytes */
 	unsigned char	fName[32];	/* a STR32 */
 	unsigned char	folder;		/* set to 1 if a folder */
 	unsigned short	foldersize;	/* number of entries in folder */
