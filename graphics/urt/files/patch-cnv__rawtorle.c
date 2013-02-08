--- cnv/rawtorle.c.orig	1992-03-24 12:53:43.000000000 +0900
+++ cnv/rawtorle.c	2012-10-16 00:15:58.000000000 +0900
@@ -66,7 +66,7 @@
      }\
 }
 
-void
+int
 main(argc,argv) 
 int argc;
 char *argv[];
