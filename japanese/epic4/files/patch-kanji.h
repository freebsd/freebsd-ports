--- include/kanji.h.orig	Mon Dec  4 03:44:17 2000
+++ include/kanji.h	Mon Dec  4 03:44:17 2000
@@ -0,0 +1,9 @@
+/* kanji.h */
+#ifndef __kanji_h__
+#define __kanji_h__
+
+#define ISKANJI(c) (0x80 & (unsigned char)(c))
+extern int Euc2Jis(unsigned char *eucstr, char *jisstr, int limit);
+extern void Jis2Euc(char *jisstr, unsigned char *eucstr);
+
+#endif
