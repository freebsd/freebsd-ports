--- macunpack/zma.h.orig	Fri Apr 16 01:04:19 1999
+++ macunpack/zma.h	Fri Apr 16 01:04:29 1999
@@ -20,7 +20,7 @@
 #define	Z_RCRC		44	/* Resource crc */
 #define	Z_FNAME		46	/* File name length and name */
 
-typedef struct fileHdr {		/* 78 bytes */
+struct fileHdr {		/* 78 bytes */
 	char		deleted;	/* Not in original, split off from: */
 	char		what;		/* What kind?  Negative if deleted */
 	unsigned char	hlen ;		/* Header length */
