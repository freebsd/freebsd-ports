--- src/crcio.c.orig	2000-10-04 14:57:38 UTC
+++ src/crcio.c
@@ -66,8 +66,7 @@ calccrc(p, n)
 
 /* ------------------------------------------------------------------------ */
 void
-fillbuf(n)			/* Shift bitbuf n bits left, read n bits */
-	unsigned char   n;
+fillbuf(unsigned char n) /* Shift bitbuf n bits left, read n bits */
 {
 	while (n > bitcount) {
 		n -= bitcount;
@@ -87,8 +86,7 @@ fillbuf(n)			/* Shift bitbuf n bits left
 
 /* ------------------------------------------------------------------------ */
 unsigned short
-getbits(n)
-	unsigned char   n;
+getbits(unsigned char n)
 {
 	unsigned short  x;
 
@@ -99,9 +97,7 @@ getbits(n)
 
 /* ------------------------------------------------------------------------ */
 void
-putcode(n, x)			/* Write rightmost n bits of x */
-	unsigned char   n;
-	unsigned short  x;
+putcode(unsigned char n, unsigned short x) /* Write rightmost n bits of x */
 {
 	while (n >= bitcount) {
 		n -= bitcount;
@@ -126,9 +122,7 @@ putcode(n, x)			/* Write rightmost n bit
 
 /* ------------------------------------------------------------------------ */
 void
-putbits(n, x)			/* Write rightmost n bits of x */
-	unsigned char   n;
-	unsigned short  x;
+putbits(unsigned char n, unsigned short x) /* Write rightmost n bits of x */
 {
 	x <<= USHRT_BIT - n;
 	while (n >= bitcount) {
@@ -308,7 +302,7 @@ fread_txt(p, n, fp)
 				c = '\r';
 			}
 #ifdef EUC
-			else if (euc_mode && (c == 0x8E || 0xA0 < c && c < 0xFF)) {
+			else if (euc_mode && (c == 0x8E || (0xA0 < c && c < 0xFF))) {
 				int             d = fgetc(fp);
 				if (d == EOF) {
 					*p++ = c;
