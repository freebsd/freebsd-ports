--- drawcgm/cgmgen.c.orig	Tue Sep  1 23:24:48 1992
+++ drawcgm/cgmgen.c	Sat Jun 16 00:59:41 2007
@@ -67,6 +67,7 @@
 #endif
 #ifdef USE_UNIX
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #endif
 #ifdef ardent
@@ -296,6 +297,10 @@
 case 1: out= ( (*ptr >> (7-bit)) & 1 ); bit= bit + 1;			\
 if (bit == 8) { bit = 0; ++ptr; }; }					\
 
+static int cgmfree();
+static unsigned int ibufsz();
+static unsigned int pbufsz();
+
 igtmem(psz)
 /*
 	This routine returns a pointer to available memory;  it is included
@@ -303,7 +308,6 @@
 */
 int *psz;
 {
-	char *malloc();
 	if (debugmode) fprintf(stderr," IGTMEM:  allocating %d bytes.\n",*psz);
 	return((int) malloc( (unsigned int) *psz ));
 }
@@ -389,7 +393,7 @@
 static void checkbufsize(newsize)
 unsigned int newsize;
 {
-	char *malloc(),*realloc(),msgbuf[256];
+	char msgbuf[256];
 
        	if ( newsize > datasize )
 		{
@@ -1045,7 +1049,7 @@
 */
 {
 	float *clrptr, *tblend;
-	char *realloc(),msgbuf[256];
+	char msgbuf[256];
 
 	if (debugmode) fprintf(stderr," wrmxci: max color index= %d\n",
 		*maxclrindx);
