--- ./contrib/binutils/gas/config/tc-arm.c.orig	2014-01-16 21:40:13.000000000 +0100
+++ ./contrib/binutils/gas/config/tc-arm.c	2015-02-18 21:57:22.653597000 +0100
@@ -6060,7 +6060,7 @@
 
 /* Functions for operand encoding.  ARM, then Thumb.  */
 
-#define rotate_left(v, n) (v << n | v >> (32 - n))
+#define rotate_left(v, n) (v << (n % 32) | v >> ((32 - n) % 32))
 
 /* If VAL can be encoded in the immediate field of an ARM instruction,
    return the encoded form.  Otherwise, return FAIL.  */
