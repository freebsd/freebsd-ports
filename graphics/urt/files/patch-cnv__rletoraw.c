--- cnv/rletoraw.c.orig	1992-04-30 23:00:21.000000000 +0900
+++ cnv/rletoraw.c	2012-10-16 00:14:10.000000000 +0900
@@ -65,7 +65,7 @@
     }\
     
 
-void
+int
 main(argc,argv) 
 int argc;
 char *argv[];
