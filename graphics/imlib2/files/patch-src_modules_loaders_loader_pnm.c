--- src/modules/loaders/loader_pnm.c.orig	Wed Nov  8 19:48:10 2006
+++ src/modules/loaders/loader_pnm.c	Wed Nov  8 19:48:51 2006
@@ -80,7 +80,7 @@
              int                 i = 0;
 
              /* read numbers */
-             while (c != EOF && !isspace(c))
+             while (c != EOF && !isspace(c) && (sizeof(buf) < (i + 1)))
                {
                   buf[i++] = c;
                   c = fgetc(f);
