--- gnomoradio/browser-link.cc.orig	2007-12-06 15:46:11.000000000 +0100
+++ gnomoradio/browser-link.cc	2007-12-06 15:48:02.000000000 +0100
@@ -32,7 +32,7 @@
 {
 	gchar *my_url = g_strdup(Glib::locale_from_utf8(url).c_str());
 	if (fork() == 0) {
-		char *const argv[] = {"gnome-moz-remote", "--newwin", my_url, 0};
+		char *const argv[] = {(char *)"gnome-moz-remote", (char *)"--newwin", my_url, 0};
 		execvp(argv[0], argv);
 		
 		// if we made it here something went wrong
