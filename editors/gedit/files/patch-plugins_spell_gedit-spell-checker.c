--- plugins/spell/gedit-spell-checker.c.orig	Wed Dec  1 20:03:36 2004
+++ plugins/spell/gedit-spell-checker.c	Wed Dec  1 20:03:59 2004
@@ -319,9 +319,9 @@
 static const GeditLanguage*
 get_language_from_abrev (const gchar *abrev)
 {
+	const GSList *langs;
 	g_return_val_if_fail (abrev != NULL, NULL);
 
-	const GSList *langs;
 	langs = gedit_spell_checker_get_available_languages ();
 
 	while (langs != NULL)
