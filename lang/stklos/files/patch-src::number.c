--- src/number.c.orig	Sat Feb  8 05:31:25 2003
+++ src/number.c	Thu Apr 10 00:15:24 2003
@@ -2903,7 +2903,7 @@
  */
 int STk_init_number(void)
 {
-#if defined(__linux__) && defined(__alpha__)
+#if defined(__alpha__)
   static union {
     unsigned char a[4];
     float f;
