--- generate.c.orig	2025-01-16 13:10:40 UTC
+++ generate.c
@@ -151,7 +151,7 @@ fatal(const char *s,...)
 {
     va_list         argptr;
 
-    if (infile) fprintf(stderr, "generate: file %s line %ld: ", infile->name, infile->xline);
+    if (infile) fprintf(stderr, "generate: file %s line %zu: ", infile->name, infile->xline);
     else fprintf(stderr, "generate: ");
 
     va_start(argptr, s);
