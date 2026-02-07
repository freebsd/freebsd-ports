--- widgets.c.orig	2020-08-26 20:41:16 UTC
+++ widgets.c
@@ -101,7 +101,7 @@ Pixmap	px_horiz,
 	px_middle,
 	px_wide;
 
-XtTranslations txt_trans;	/* translations for numeric entries */
+extern XtTranslations txt_trans;	/* translations for numeric entries */
 XtTranslations name_trans;	/* translations for name-entry */
 
 static void fchs_cb(Widget, XtPointer, XtPointer);
