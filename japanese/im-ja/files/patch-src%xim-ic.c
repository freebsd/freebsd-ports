Index: src/xim-ic.c
diff -u -p src/xim-ic.c.orig src/xim-ic.c
--- src/xim-ic.c.orig	Wed Dec 17 13:17:26 2003
+++ src/xim-ic.c	Wed Mar 24 21:12:11 2004
@@ -572,9 +572,9 @@ static void im_ja_xim_ic_set_preedit_bac
 
 
 static void im_ja_xim_ic_load_preedit_fontset(IMJAContext *ic, char *font_name) {
-	IM_JA_DEBUG("im_ja_xim_ic_load_preedit_fontset\n");
-
 	IMJAXimFontSet *fontset;
+
+	IM_JA_DEBUG("im_ja_xim_ic_load_preedit_fontset\n");
 
 	if (ic->preedit.base_font != NULL && strcmp(ic->preedit.base_font, font_name) == 0) {
 		// same font, do not create fontset
