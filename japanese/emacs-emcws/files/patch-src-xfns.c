--- src/xfns.c.orig	2002-12-06 18:05:35.000000000 +0100
+++ src/xfns.c	2012-05-02 19:50:40.000000000 +0200
@@ -8541,7 +8541,7 @@
 {
   xassert (png_ptr != NULL);
   image_error ("PNG error: %s", build_string (msg), Qnil);
-  longjmp (png_ptr->jmpbuf, 1);
+  longjmp (png_jmpbuf(png_ptr), 1);
 }
 
 
@@ -8641,7 +8641,7 @@
 
       /* Check PNG signature.  */
       if (fread (sig, 1, sizeof sig, fp) != sizeof sig
-	  || !png_check_sig (sig, sizeof sig))
+	  || png_sig_cmp (sig, 0, sizeof sig))
 	{
 	  image_error ("Not a PNG file: `%s'", file, Qnil);
 	  UNGCPRO;
@@ -8658,7 +8658,7 @@
 
       /* Check PNG signature.  */
       if (tbr.len < sizeof sig
-	  || !png_check_sig (tbr.bytes, sizeof sig))
+	  || png_sig_cmp (tbr.bytes, 0, sizeof sig))
 	{
 	  image_error ("Not a PNG image: `%s'", img->spec, Qnil);
 	  UNGCPRO;
@@ -8699,7 +8699,7 @@
 
   /* Set error jump-back.  We come back here when the PNG library
      detects an error.  */
-  if (setjmp (png_ptr->jmpbuf))
+  if (setjmp (png_jmpbuf(png_ptr)))
     {
     error:
       if (png_ptr)
