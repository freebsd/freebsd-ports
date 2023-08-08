--- compose/asc-globals.c.orig	2023-02-10 19:54:13 UTC
+++ compose/asc-globals.c
@@ -455,7 +455,7 @@ gchar**
  * Returns: (transfer full): A list of valid hint tags. Free with %g_strfreev
  */
 gchar**
-asc_globals_get_hint_tags ()
+asc_globals_get_hint_tags (void)
 {
 	AscGlobalsPrivate *priv = asc_globals_get_priv ();
 	GHashTableIter iter;
