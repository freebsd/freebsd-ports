--- src/xsane-save.c.orig	2010-11-16 21:06:00 UTC
+++ src/xsane-save.c
@@ -4910,7 +4910,7 @@ int xsane_save_png(FILE *outfile, int co
     return -1; /* error */
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     snprintf(buf, sizeof(buf), "%s %s", ERR_DURING_SAVE, ERR_LIBPNG);
     xsane_back_gtk_error(buf, TRUE);
@@ -5100,7 +5100,7 @@ int xsane_save_png_16(FILE *outfile, int
     return -1; /* error */
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     snprintf(buf, sizeof(buf), "%s %s", ERR_DURING_SAVE, ERR_LIBPNG);
     xsane_back_gtk_error(buf, TRUE);
