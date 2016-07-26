--- macunpack/jdw.h.orig	1993-10-02 20:16:00 UTC
+++ macunpack/jdw.h
@@ -8,7 +8,7 @@
 #define	J_MTIME		34
 #define	J_FLENGTH	38
 
-typedef struct fileHdr {
+struct fileHdr {
 	char		magic[6];
 	unsigned long	type;
 	unsigned long	auth;
