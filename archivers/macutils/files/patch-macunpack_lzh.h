--- macunpack/lzh.h.orig	1993-10-02 20:16:00 UTC
+++ macunpack/lzh.h
@@ -30,7 +30,7 @@
 #define L_EEXTENDSZ	0
 #define L_EEXTEND	1
 
-typedef struct fileHdr { /* 58 bytes */
+struct fileHdr { /* 58 bytes */
 	unsigned char	hsize;
 	unsigned char	hcrc;
 	char		method[5];
