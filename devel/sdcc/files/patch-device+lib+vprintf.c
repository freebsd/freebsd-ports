--- device/lib/vprintf.c.orig
+++ device/lib/vprintf.c
@@ -292,7 +292,7 @@
 
   unsigned char  width;
   signed char decimals;
-  unsigned char  length;
+  volatile unsigned char  length;
   char           c;
 
   // reset output chars
