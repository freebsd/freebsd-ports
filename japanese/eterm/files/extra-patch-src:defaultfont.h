--- src/defaultfont.h.orig	Tue Aug 26 09:35:29 2003
+++ src/defaultfont.h	Sun Jan 18 05:39:35 2004
@@ -95,9 +95,9 @@
 #define NFONT_LIST_NULL NFONT_LIST_10646
 #define MFONT_LIST_NULL MFONT_LIST_10646
 
-#define DEF_EUCJ 1
-#define NFONT_LIST_EUCJ "6x12","7x14", "8x16", "9x18", "12x24"
-#define MFONT_LIST_EUCJ "k12", "k14", "kanji16", "k18", "kanji24"
+#define DEF_EUCJ 0
+#define NFONT_LIST_EUCJ "7x14","a10", "r12", "8x16", "12x24"
+#define MFONT_LIST_EUCJ "k14", "k10", "k12", "kanji16", "kanji24"
 
 #define DEF_GB 0
 #define NFONT_LIST_GB   "8x16", "12x24", "", "", ""
