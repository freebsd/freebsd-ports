--- desktop.c.orig	2009-05-24 18:56:39.000000000 +0300
+++ desktop.c	2009-05-24 18:56:44.000000000 +0300
@@ -26,7 +26,7 @@
 /* desktop files are in utf-8                                                */
 
 static int iconv_string(char *to, char *from,
-			char *src, char *dst, size_t max)
+			const char *src, char *dst, size_t max)
 {
     size_t ilen = strlen(src);
     size_t olen = max-1;
