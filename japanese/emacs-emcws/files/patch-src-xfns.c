--- src/xfns.c.orig	2002-12-06 18:05:35.000000000 +0100
+++ src/xfns.c	2010-03-30 06:35:54.000000000 +0200
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
