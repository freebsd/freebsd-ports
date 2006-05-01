--- unix/arlib.c.orig	Mon May  1 18:35:44 2006
+++ unix/arlib.c	Mon May  1 18:37:16 2006
@@ -421,7 +421,7 @@
    fseek(f, arhdroffset + (unsigned long)(((struct ar_hdr *)0)->ar_date), 0);
 
 #if ASCARCH
-   fprintf(f, "%lu", now);
+   fprintf(f, "%llu", (unsigned long long)now);
 #else
    fwrite((char *)now, sizeof(now), 1, f);
 #endif
