Clang compatibility
--- src/about.c.orig	2006-08-09 22:50:25.000000000 +0400
+++ src/about.c	2013-06-13 20:38:32.250111722 +0400
@@ -232,7 +232,7 @@
 /* Closes the splash screen */
 gboolean kudu_about_splash_close(void)
 {
-	if (splash_win == NULL) return;
+	if (splash_win == NULL) return FALSE;
 
 	gulong ms;
 
