--- xvi.h.orig	Tue Aug 27 14:27:05 2002
+++ xvi.h	Tue Aug 27 14:27:05 2002
@@ -151,11 +151,7 @@
 #   else
 #       define KANJI_VER	"jXvi K.Tsuchida"
 #   endif
-#   ifdef MSDOS
 #       define DEF_KCODE	kc_SJIS
-#   else
-#       define DEF_KCODE	kc_EUC
-#   endif
 #else
 #   undef  FEPCTRL
 #   undef  KANJI_INDENT
