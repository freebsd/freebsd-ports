Clang compatibility
--- src/about.c.orig	2006-08-09 18:50:25 UTC
+++ src/about.c
@@ -232,7 +232,7 @@ void kudu_about_splash_set_parent(GtkWin
 /* Closes the splash screen */
 gboolean kudu_about_splash_close(void)
 {
-	if (splash_win == NULL) return;
+	if (splash_win == NULL) return FALSE;
 
 	gulong ms;
 
