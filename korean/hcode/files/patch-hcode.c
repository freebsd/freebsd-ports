--- hcode.c.orig	1998-03-11 04:46:36.000000000 -0500
+++ hcode.c	2013-06-12 20:13:26.000000000 -0400
@@ -13,8 +13,10 @@
  update for new Hangul Code including UNICODE.
 ************************************************************ */
 
+#include <ctype.h>
 #include <stdio.h>
-#include <strings.h>
+#include <stdlib.h>
+#include <string.h>
 #include "hcode.h"
 
 extern void pr2m();
@@ -37,9 +39,8 @@
                              0 on success from filtering programs. jshin */
 char *basename();        /* strips  directory */
 
-main(argc,argv)
-int argc;
-char *argv[];
+int
+main(int argc, char *argv[])
 {
 	int inCode, outCode;
 	FILE *fpin, *fpout;
@@ -60,8 +61,8 @@
 		prwc = pr2m;
 	}
 
+	getwc = getks;
 	if ( inCode == KS || inCode == H3 ) {
-		getwc = getks;
                 if ( outCode == IS && inCode == KS )
 	            iseof = putprolog(fpin,fpout);                
 	}
