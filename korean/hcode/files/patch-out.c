--- out.c.orig	1998-03-11 04:46:36.000000000 -0500
+++ out.c	2013-06-12 19:05:40.000000000 -0400
@@ -23,7 +23,7 @@
 {
 	static unsigned long int (*conv)();
 	static unsigned int MSB=0xff;
-        static unsigned char StartC=NULL, EndC=NULL;
+        static unsigned char StartC='\0', EndC='\0';
         static int initialized=0;
 
 	/* if ( prstat == PRNONE ) { */
@@ -45,7 +45,7 @@
            		 
 
         if ( wc>>8 == 0 ) {
-                if (prstat==PRINTING && EndC!=NULL) putc(EndC,fpout);
+                if (prstat==PRINTING && EndC!='\0') putc(EndC,fpout);
                 if (prstat == PRINTING) prstat = PRINTED;
                 /* to make 'hcode -ki | hcode -ki' work: jshin(7/18/96) */
 		if ( wc == StartC && ! (outCode==IS||outCode==SD) )  
@@ -62,7 +62,7 @@
 
 	wc = (*conv)(wc);
 
-	if ( prstat == PRINTED && StartC != NULL )
+	if ( prstat == PRINTED && StartC != '\0' )
 		putc(StartC,fpout);
 
 	if ( wc>>16 == 0 ||  wc>>16 == 0x8ffb ) {	/* TR, KS */
@@ -87,7 +87,7 @@
 {
 	static int C;
         int ch,ju,jo;
-	static unsigned char StartC=NULL, EndC=NULL;
+	static unsigned char StartC='\0', EndC='\0';
 
         if ( prstat == PRNONE ) {
         	C=outCode-NB;
@@ -97,7 +97,7 @@
         }
 
         if ( wc>>8 == 0 ) {
-                if (prstat == PRINTING && EndC != NULL) putc(EndC,fpout);
+                if (prstat == PRINTING && EndC != '\0') putc(EndC,fpout);
 		if (prstat == PRINTING) prstat = PRINTED;
 		if ( wc == StartC ) putc((char)wc,fpout);
                 putc((char)wc,fpout);
