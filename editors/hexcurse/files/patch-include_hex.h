--- include/hex.h.orig	2015-11-18 04:33:09 UTC
+++ include/hex.h
@@ -126,7 +126,7 @@ extern bool color_enabled;
 #define max(a,b) ((a) >(b) ? (a) : (b))
 #endif
 
-FILE *fpIN;		        		/* global file ptr           */
+extern FILE *fpIN;		       		/* global file ptr           */
 
 /* function prototypes */
 
