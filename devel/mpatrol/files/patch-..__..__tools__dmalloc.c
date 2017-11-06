--- ../../tools/dmalloc.c.orig	2002-01-08 20:05:10 UTC
+++ ../../tools/dmalloc.c
@@ -395,7 +395,7 @@ static
 char *
 bytestring(char *b, size_t s, char *p, size_t l)
 {
-    char *t;
+    const char *t;
     size_t i, n;
 
     for (i = n = 0; (i < s) && (i < l); i++)
