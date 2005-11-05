--- src/svg2pdf.c.orig	Fri Aug  5 22:17:31 2005
+++ src/svg2pdf.c	Fri Aug  5 22:17:48 2005
@@ -49,9 +49,9 @@ int 
 main (int argc, char **argv)
 {
     args_t args;
-    args_parse (&args, argc, argv);
     FILE *svg_file, *pdf_file;
     svg_cairo_status_t status;
+    args_parse (&args, argc, argv);
 
     if (strcmp (args.svg_filename, "-") == 0) {
 	svg_file = stdin;
