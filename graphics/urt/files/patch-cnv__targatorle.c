--- cnv/targatorle.c.orig	1992-02-28 06:11:12.000000000 +0900
+++ cnv/targatorle.c	2012-10-15 22:51:12.000000000 +0900
@@ -119,7 +119,7 @@
 void init_comp();
 unsigned char getbyte();
 
-void
+int
 main(argc,argv) 
 int argc;
 char *argv[];
