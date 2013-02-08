--- cnv/rletotarga.c.orig	1992-01-22 04:37:07.000000000 +0900
+++ cnv/rletotarga.c	2012-10-15 22:47:54.000000000 +0900
@@ -62,7 +62,7 @@
                       image_descriptor;       /* Image Descriptor Byte */
       };
 
-void
+int
 main(argc,argv) 
 int argc;
 char *argv[];
