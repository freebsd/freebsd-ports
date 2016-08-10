--- tests/validate.c.orig	2016-08-10 11:23:44.131844000 +0200
+++ tests/validate.c	2016-08-10 11:24:56.257698000 +0200
@@ -2394,7 +2394,7 @@
       else
         {
           (void) FormatLocaleFile(stdout,"Version: %s\n",
-            GetMagickHomeURL();
+            GetMagickVersion((size_t *) NULL));
           (void) FormatLocaleFile(stdout,"Copyright: %s\n\n",
             GetMagickCopyright());
           (void) FormatLocaleFile(stdout,
