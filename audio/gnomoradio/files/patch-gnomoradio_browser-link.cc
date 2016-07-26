--- gnomoradio/browser-link.cc.orig	2004-10-17 01:41:23 UTC
+++ gnomoradio/browser-link.cc
@@ -32,7 +32,7 @@ static void mozilla_fallback (const Glib
 {
 	gchar *my_url = g_strdup(Glib::locale_from_utf8(url).c_str());
 	if (fork() == 0) {
-		char *const argv[] = {"gnome-moz-remote", "--newwin", my_url, 0};
+		char *const argv[] = {(char *)"gnome-moz-remote", (char *)"--newwin", my_url, 0};
 		execvp(argv[0], argv);
 		
 		// if we made it here something went wrong
