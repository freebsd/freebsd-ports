--- include/hex.h.orig	2003-12-23 03:08:25 UTC
+++ include/hex.h
@@ -111,7 +111,7 @@ extern char EBCDIC[256];
 #define max(a,b) ((a) >(b) ? (a) : (b))
 #endif
 
-FILE *fpIN, *fpOUT;				/* global file ptrs           */
+extern FILE *fpIN, *fpOUT;			/* global file ptrs           */
 
 /* function prototypes */
 
