--- src/image.c.orig	2008-08-26 00:18:33.000000000 +0200
+++ src/image.c	2012-06-03 11:17:01.000000000 +0200
@@ -6338,7 +6338,7 @@
 /* PNG library details.  */
 
 DEF_IMGLIB_FN (png_get_io_ptr);
-DEF_IMGLIB_FN (png_check_sig);
+DEF_IMGLIB_FN (png_sig_cmp);
 DEF_IMGLIB_FN (png_create_read_struct);
 DEF_IMGLIB_FN (png_create_info_struct);
 DEF_IMGLIB_FN (png_destroy_read_struct);
@@ -6369,7 +6369,7 @@
     return 0;
 
   LOAD_IMGLIB_FN (library, png_get_io_ptr);
-  LOAD_IMGLIB_FN (library, png_check_sig);
+  LOAD_IMGLIB_FN (library, png_sig_cmp);
   LOAD_IMGLIB_FN (library, png_create_read_struct);
   LOAD_IMGLIB_FN (library, png_create_info_struct);
   LOAD_IMGLIB_FN (library, png_destroy_read_struct);
@@ -6394,7 +6394,7 @@
 #else
 
 #define fn_png_get_io_ptr		png_get_io_ptr
-#define fn_png_check_sig		png_check_sig
+#define fn_png_sig_cmp			png_sig_cmp
 #define fn_png_create_read_struct	png_create_read_struct
 #define fn_png_create_info_struct	png_create_info_struct
 #define fn_png_destroy_read_struct	png_destroy_read_struct
@@ -6427,7 +6427,7 @@
 {
   xassert (png_ptr != NULL);
   image_error ("PNG error: %s", build_string (msg), Qnil);
-  longjmp (png_ptr->jmpbuf, 1);
+  longjmp (png_jmpbuf(png_ptr), 1);
 }
 
 
@@ -6541,7 +6541,7 @@
 
       /* Check PNG signature.  */
       if (fread (sig, 1, sizeof sig, fp) != sizeof sig
-	  || !fn_png_check_sig (sig, sizeof sig))
+	  || fn_png_sig_cmp (sig, 0, sizeof sig))
 	{
 	  image_error ("Not a PNG file: `%s'", file, Qnil);
 	  UNGCPRO;
@@ -6558,7 +6558,7 @@
 
       /* Check PNG signature.  */
       if (tbr.len < sizeof sig
-	  || !fn_png_check_sig (tbr.bytes, sizeof sig))
+	  || fn_png_sig_cmp (tbr.bytes, 0, sizeof sig))
 	{
 	  image_error ("Not a PNG image: `%s'", img->spec, Qnil);
 	  UNGCPRO;
@@ -6603,7 +6603,7 @@
 
   /* Set error jump-back.  We come back here when the PNG library
      detects an error.  */
-  if (setjmp (png_ptr->jmpbuf))
+  if (setjmp (png_jmpbuf(png_ptr)))
     {
     error:
       if (png_ptr)
