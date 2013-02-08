--- cnv/tifftorle.c.orig	1992-08-07 04:44:25.000000000 +0900
+++ cnv/tifftorle.c	2012-10-16 00:13:07.000000000 +0900
@@ -47,7 +47,7 @@
 unsigned char bc2[4] = { 0, 0x55, 0xaa, 0xff };
 unsigned char bc1[2] = { 0, 0xff };
  
-void
+int
 main(argc, argv)
 int argc;
 char *argv[];
