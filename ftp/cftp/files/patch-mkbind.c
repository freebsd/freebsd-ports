$OpenBSD: patch-mkbind_c,v 1.1 2003/04/15 15:50:11 avsm Exp $
--- mkbind.c.orig	2002-09-17 11:46:23 UTC
+++ mkbind.c
@@ -86,7 +86,7 @@ int
 main(int argc, char **argv)
 {
     FILE *fin, *fout;
-    char line[4069], *p, *tok, **args;
+    char line[4096], *p, *tok, **args;
     char tmp[128];
     struct binding *b;
     int i, j, off, argoff, len;
