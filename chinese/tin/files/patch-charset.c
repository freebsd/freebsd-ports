--- src/charset.c.orig	Wed Jan  8 23:12:11 2003
+++ src/charset.c	Wed Jan  8 23:12:28 2003
@@ -443,7 +443,7 @@
 	unsigned char *c;
 
 	for (c = (unsigned char *) buf; *c; c++) {
-		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13))
+		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13 || *c == 27))
 			*c = '?';
 	}
 #endif /* MULTIBYTE_ABLE && !NO_LOCALE */
