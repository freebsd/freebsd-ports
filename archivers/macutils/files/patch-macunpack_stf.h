--- macunpack/stf.h.orig	1993-10-02 20:16:00 UTC
+++ macunpack/stf.h
@@ -5,7 +5,7 @@
 #define	S_RSRCLNGTH	3	/* + NAMELENGTH */
 #define	S_DATALNGTH	7	/* + NAMELENGTH */
 
-typedef struct fileHdr {
+struct fileHdr {
 	char		magic[3];
 	char		flength;
 	char		fname[32];	/* actually flength */
