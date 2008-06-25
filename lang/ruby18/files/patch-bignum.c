--- bignum.c.orig	2007-09-19 06:13:21.000000000 +0400
+++ bignum.c	2008-06-26 01:54:38.000000000 +0400
@@ -652,6 +652,9 @@
     if (BIGZEROP(x)) {
 	return rb_str_new2("0");
     }
+    if (i >= LONG_MAX/SIZEOF_BDIGITS/CHAR_BIT) {
+	rb_raise(rb_eRangeError, "bignum too big to convert into `string'");
+    }
     j = SIZEOF_BDIGITS*CHAR_BIT*i;
     switch (base) {
       case 2: break;
