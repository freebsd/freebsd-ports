--- desktop.c.orig	2017-08-30 10:48:03 UTC
+++ desktop.c
@@ -27,7 +27,7 @@ extern int debug;
 /* desktop files are in utf-8                                                */
 
 static int iconv_string(char *to, char *from,
-			char *src, char *dst, size_t max)
+			const char *src, char *dst, size_t max)
 {
     size_t ilen = strlen(src);
     size_t olen = max-1;
