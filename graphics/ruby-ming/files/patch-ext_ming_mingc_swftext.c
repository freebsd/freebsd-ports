--- ext/ming/mingc/swftext.c.orig	2011-08-08 14:06:21.000000000 +0000
+++ ext/ming/mingc/swftext.c	2011-08-08 14:07:20.000000000 +0000
@@ -150,7 +150,7 @@
   if (advance == Qnil) {
     adv = 0;
   } else {
-    len = RARRAY(advance)->len;
+    len = RARRAY_LEN(advance);
     adv = ALLOC_N(int, len);
     
     /* unefficient, but easy to implement... */
