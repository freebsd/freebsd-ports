--- xvi.h.orig	Wed Dec 18 20:50:06 2002
+++ xvi.h	Wed Dec 18 20:50:43 2002
@@ -90,9 +90,9 @@
  * Functions which ANSI does not specify should
  * be included in any standard header file.
  */
+#ifndef BSD386	/* ken */
 extern	int	chdir P((const char *path));
 extern	char	*getcwd P((char *, unsigned));
-#ifndef BSD386	/* ken */
 extern	void	sleep P((unsigned seconds));
 #endif
 
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
