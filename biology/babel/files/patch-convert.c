
$FreeBSD$

--- convert.c.orig	Sun Nov 18 16:44:25 2001
+++ convert.c	Sun Nov 18 16:44:54 2001
@@ -28,6 +28,7 @@
 static warning wstr;
 
 static char *program_name;
+extern char *__progname;
 int use_title = FALSE;
 
 #ifdef MSDOS
@@ -47,7 +48,7 @@
 #endif
 
   babel_init();
-  program_name = argv[0];
+  program_name = __progname;
   if (argc == 1)
   {
     usage();
