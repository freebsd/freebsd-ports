--- texk/xdvik/fontconfig.h.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/fontconfig.h
@@ -0,0 +1,11 @@
+
+#ifndef FONTCONFIG_H_
+#define FONTCONFIG_H_
+
+#ifdef	PTEX
+
+char *get_ptex_font_pathname(char *name);
+
+#endif /* PTEX */
+
+#endif /* FONTCONFIG_H_ */
