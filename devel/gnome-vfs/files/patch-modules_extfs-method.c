--- modules/extfs-method.c.orig	Thu Aug 12 20:04:05 2004
+++ modules/extfs-method.c	Thu Aug 12 20:06:20 2004
@@ -61,7 +61,7 @@
 
 
 static ssize_t
-getdelim (char **lineptr, size_t n, int terminator, FILE *stream)
+getdelim (char **lineptr, size_t *n, int terminator, FILE *stream)
 {
 	char *line, *p;
 	size_t size, copy;
