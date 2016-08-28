--- src/gdft.c.orig	2016-07-21 10:32:27.000000000 +0200
+++ src/gdft.c	2016-08-28 19:25:01.730120000 +0200
@@ -139,7 +139,7 @@
 }
 #else
 
-#ifndef HAVE_LIBFONTCONFIG
+#if 0
 static char * font_pattern(char **fontpath, char *fontpattern)
 {
 	(void)fontpath;
@@ -446,15 +446,15 @@
 	return (strcmp (a->fontlist, b->fontlist) == 0 && a->flags == b->flags);
 }
 
+#ifdef HAVE_LIBFONTCONFIG
 static int useFontConfig(int flag)
 {
-#ifdef HAVE_LIBFONTCONFIG
 	if (fontConfigFlag) {
 		return (!(flag & gdFTEX_FONTPATHNAME));
 	}
-#endif
 	return flag & gdFTEX_FONTCONFIG;
 }
+#endif
 
 static void *
 fontFetch (char **error, void *key)
