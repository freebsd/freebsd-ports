--- ./admesh.c.orig	1996-07-27 00:07:15.000000000 +0200
+++ ./admesh.c	2012-10-27 21:01:18.374482756 +0200
@@ -27,7 +27,7 @@
 
 static void usage(int status, char *program_name);
 
-void
+int
 main(int argc, char **argv)
 {
   stl_file stl_in;
