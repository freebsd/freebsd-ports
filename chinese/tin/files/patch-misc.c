--- src/misc.c.orig	Thu Aug  3 21:49:22 2000
+++ src/misc.c	Mon Apr  9 00:47:20 2001
@@ -1169,6 +1169,7 @@
 my_isprint (
 	int c)
 {
+	return (isprint(c) || (c>=0x40 && c<=0xfe));
 #ifndef NO_LOCALE
 	/* use locale */
 	return isprint(c);
