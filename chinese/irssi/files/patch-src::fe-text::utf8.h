--- src/fe-text/utf8.h.orig	Mon Oct 20 03:10:02 2003
+++ src/fe-text/utf8.h	Wed Apr  7 11:06:22 2004
@@ -18,6 +18,10 @@
    Make sure out is at least 6 x length of str. */
 void utf16_to_utf8(const unichar *str, char *out);
 
+/* unichar -> UTF-8 string with position transformed. The NUL is copied as well.
+   Make sure out is at least 6 x length of str. */
+void utf16_to_utf8_with_pos(const unichar *str, int spos, char *out, int *opos);
+
 /* XXX I didn't check the encoding range of big5+. This is standard big5. */
 #define is_big5_los(lo) (0x40 <= (lo) && (lo) <= 0x7E) /* standard */
 #define is_big5_lox(lo) (0x80 <= (lo) && (lo) <= 0xFE) /* extended */
