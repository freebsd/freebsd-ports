$FreeBSD$

--- hybridize.c.orig	Sat Nov 24 21:25:04 2001
+++ hybridize.c	Sat Nov 24 21:25:35 2001
@@ -54,6 +54,7 @@
 extern unsigned array_to_base_4();
 extern unsigned string_to_base_4();
 extern int dna2i();
+double logl();
 int *read_file();
 
 main(argc, argv)
