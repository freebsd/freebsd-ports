--- gas/config/tc-arm.c.orig	2015-07-21 08:20:58 UTC
+++ gas/config/tc-arm.c
@@ -7261,7 +7261,7 @@ parse_operands (char *str, const unsigne
 
 /* Functions for operand encoding.  ARM, then Thumb.  */
 
-#define rotate_left(v, n) (v << n | v >> (32 - n))
+#define rotate_left(v, n) (v << (n & 31) | v >> ((32 - n) & 31))
 
 /* If VAL can be encoded in the immediate field of an ARM instruction,
    return the encoded form.  Otherwise, return FAIL.  */
