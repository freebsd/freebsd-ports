--- src/fe-text/term-terminfo.c.orig	Sun May 12 22:48:11 2002
+++ src/fe-text/term-terminfo.c	Sat Nov 23 17:28:36 2002
@@ -564,12 +564,6 @@
 	}
 }
 
-/* XXX I didn't check the encoding range of big5+. This is standard big5. */
-#define is_big5_los(lo) (0x40 <= (lo) && (lo) <= 0x7E) /* standard */
-#define is_big5_lox(lo) (0x80 <= (lo) && (lo) <= 0xFE) /* extended */
-#define is_big5_hi(hi)  (0x81 <= (hi) && (hi) <= 0xFE)
-#define is_big5(hi,lo) (is_big5_hi(hi) && (is_big5_los(lo) || is_big5_lox(lo)))
-
 static int input_big5(const unsigned char *buffer, int size, unichar *result)
 {
 	if (is_big5_hi(*buffer)) {
