--- include/hex.h.orig	2015-11-17 20:33:09.000000000 -0800
+++ include/hex.h	2021-03-15 11:33:30.825153000 -0700
@@ -126,7 +126,7 @@
 #define max(a,b) ((a) >(b) ? (a) : (b))
 #endif
 
-FILE *fpIN;		        		/* global file ptr           */
+extern FILE *fpIN;		       		/* global file ptr           */
 
 /* function prototypes */
 
