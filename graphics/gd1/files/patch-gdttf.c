--- gdttf.c.orig	Fri Feb  2 05:23:56 2001
+++ gdttf.c	Wed Feb  7 20:57:34 2001
@@ -221,11 +221,10 @@
     byte = *((unsigned char *) str);
 #ifdef JISX0208
     if (0xA1 <= byte && byte <= 0xFE) {
-	int jiscode, ku, ten;
+	int ku, ten;
 
-	jiscode = 0x100 * (byte & 0x7F) + (str[1] & 0x7F);
-	ku = (jiscode >> 8) - 0x20;
-	ten = (jiscode % 256) - 0x20;
+	ku = (byte & 0x7F) - 0x20;
+	ten = (str[1] & 0x7F) - 0x20;
 	if ( (ku < 1 || ku > 92) || (ten < 1 || ten > 94) ) {
     		*chPtr = (Tcl_UniChar) byte;
     		return 1;
