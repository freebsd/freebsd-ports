--- src/svg2png.c.orig	Thu Jan 20 10:03:49 2005
+++ src/svg2png.c	Thu Mar 10 23:04:42 2005
@@ -47,9 +47,9 @@
 main (int argc, char **argv)
 {
     args_t args;
-    args_parse (&args, argc, argv);
     FILE *svg_file, *png_file;
     svg_cairo_status_t status;
+    args_parse (&args, argc, argv);
 
     if (strcmp (args.svg_filename, "-") == 0) {
 	svg_file = stdin;
