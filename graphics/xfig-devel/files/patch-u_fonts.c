--- u_fonts.c.old	2007-10-17 12:22:24.000000000 -0700
+++ u_fonts.c	2007-10-17 12:23:36.000000000 -0700
@@ -107,7 +107,7 @@
 /* PostScript font names matched with X11 font names in x_fontinfo */
 
 struct _fstruct ps_fontinfo[NUM_FONTS + 1] = {
-    {"Default", -1},
+    {"Default", 0},
     {"Times-Roman",			0},
     {"Times-Italic",			1},
     {"Times-Bold",			2},
