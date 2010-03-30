--- src/image.c.orig	2010-03-29 08:46:39.902587060 +0200
+++ src/image.c	2010-03-29 08:51:40.907908128 +0200
@@ -5793,7 +5793,7 @@
 /* PNG library details.  */
 
 DEF_IMGLIB_FN (png_get_io_ptr);
-DEF_IMGLIB_FN (png_check_sig);
+DEF_IMGLIB_FN (png_sig_cmp);
 DEF_IMGLIB_FN (png_create_read_struct);
 DEF_IMGLIB_FN (png_create_info_struct);
 DEF_IMGLIB_FN (png_destroy_read_struct);
@@ -5824,7 +5824,7 @@
     return 0;
 
   LOAD_IMGLIB_FN (library, png_get_io_ptr);
-  LOAD_IMGLIB_FN (library, png_check_sig);
+  LOAD_IMGLIB_FN (library, png_sig_cmp);
   LOAD_IMGLIB_FN (library, png_create_read_struct);
   LOAD_IMGLIB_FN (library, png_create_info_struct);
   LOAD_IMGLIB_FN (library, png_destroy_read_struct);
@@ -5849,7 +5849,7 @@
 #else
 
 #define fn_png_get_io_ptr		png_get_io_ptr
-#define fn_png_check_sig		png_check_sig
+#define fn_png_sig_cmp			png_sig_cmp
 #define fn_png_create_read_struct	png_create_read_struct
 #define fn_png_create_info_struct	png_create_info_struct
 #define fn_png_destroy_read_struct	png_destroy_read_struct
@@ -5996,7 +5996,7 @@
 
       /* Check PNG signature.  */
       if (fread (sig, 1, sizeof sig, fp) != sizeof sig
-	  || !fn_png_check_sig (sig, sizeof sig))
+	  || fn_png_sig_cmp (sig, 0, sizeof sig))
 	{
 	  image_error ("Not a PNG file: `%s'", file, Qnil);
 	  UNGCPRO;
@@ -6013,7 +6013,7 @@
 
       /* Check PNG signature.  */
       if (tbr.len < sizeof sig
-	  || !fn_png_check_sig (tbr.bytes, sizeof sig))
+	  || fn_png_sig_cmp (tbr.bytes, 0, sizeof sig))
 	{
 	  image_error ("Not a PNG image: `%s'", img->spec, Qnil);
 	  UNGCPRO;
