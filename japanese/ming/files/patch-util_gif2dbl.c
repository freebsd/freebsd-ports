--- ../util/gif2dbl.c~	2002-06-24 21:21:54.000000000 +0900
+++ ../util/gif2dbl.c	2013-03-14 04:57:51.000000000 +0900
@@ -16,7 +16,7 @@
 void error(char *msg)
 {
   printf("%s:\n\n", msg);
-  PrintGifError();
+  GifError();
   exit(-1);
 }
 
