--- ../util/gif2mask.c~	2002-06-24 21:21:54.000000000 +0900
+++ ../util/gif2mask.c	2013-03-14 04:57:54.000000000 +0900
@@ -11,7 +11,7 @@
 void error(char *msg)
 {
   printf("%s:\n\n", msg);
-  PrintGifError();
+  GifError();
   exit(-1);
 }
 
