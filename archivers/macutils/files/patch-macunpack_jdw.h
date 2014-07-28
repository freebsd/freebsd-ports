--- macunpack/jdw.h.orig	Fri Apr 16 00:13:34 1999
+++ macunpack/jdw.h	Fri Apr 16 00:13:37 1999
@@ -8,7 +8,7 @@
 #define	J_MTIME		34
 #define	J_FLENGTH	38
 
-typedef struct fileHdr {
+struct fileHdr {
 	char		magic[6];
 	unsigned long	type;
 	unsigned long	auth;
