--- src/xsane-save.c.orig	2010-11-16 22:06:00.000000000 +0100
+++ src/xsane-save.c	2012-05-04 07:37:59.000000000 +0200
@@ -4910,7 +4910,7 @@
     return -1; /* error */
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     snprintf(buf, sizeof(buf), "%s %s", ERR_DURING_SAVE, ERR_LIBPNG);
     xsane_back_gtk_error(buf, TRUE);
@@ -5100,7 +5100,7 @@
     return -1; /* error */
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     snprintf(buf, sizeof(buf), "%s %s", ERR_DURING_SAVE, ERR_LIBPNG);
     xsane_back_gtk_error(buf, TRUE);
