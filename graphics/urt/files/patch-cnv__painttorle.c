--- cnv/painttorle.c.orig	1992-01-17 06:44:02.000000000 +0900
+++ cnv/painttorle.c	2012-10-15 22:40:22.000000000 +0900
@@ -46,7 +46,7 @@
 
 void init(), read_scan(), write_scan();
 
-void
+int
 main(argc,argv) 
 int argc;
 char *argv[];
