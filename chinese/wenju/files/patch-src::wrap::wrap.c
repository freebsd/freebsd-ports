--- src/wrap/wrap.c.orig	Sat Oct 18 05:37:16 2003
+++ src/wrap/wrap.c	Sat Oct 18 05:36:19 2003
@@ -293,7 +293,7 @@
         size = 0;
         p = NULL;
         /* Read in an input line. */
-        while ((length = getline(&p, &size, fp)) > 0) {
+        while ((length = fgets(p, size, fp)) > 0) {
             if (p[0] == '\n') {
                 /* An empty line signals the end of the paragraph. */
                 if (strcmp(text->str, "\n") == 0) {
