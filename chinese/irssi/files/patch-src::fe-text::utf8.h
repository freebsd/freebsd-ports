--- src/fe-text/utf8.h.orig	Tue Oct 15 02:45:08 2002
+++ src/fe-text/utf8.h	Sat Nov 23 17:28:38 2002
@@ -18,6 +18,13 @@
    Make sure out is at least 6 x length of str. */
 void utf16_to_utf8(const unichar *str, char *out);
 
+/* XXX I didn't check the encoding range of big5+. This is standard big5. */
+#define is_big5_los(lo) (0x40 <= (lo) && (lo) <= 0x7E) /* standard */
+#define is_big5_lox(lo) (0x80 <= (lo) && (lo) <= 0xFE) /* extended */
+#define is_big5_lo(lo)	((is_big5_los(lo) || is_big5_lox(lo)))
+#define is_big5_hi(hi)  (0x81 <= (hi) && (hi) <= 0xFE)
+#define is_big5(hi,lo) (is_big5_hi(hi) && is_big5_lo(lo))
+
 /* Returns width for character (0-2). */
 int utf8_width(unichar c);
 
