--- deskbar/handlers/mozilla.py.orig	Wed Mar  1 13:32:12 2006
+++ deskbar/handlers/mozilla.py	Wed Mar  1 13:33:19 2006
@@ -189,6 +189,7 @@ class MozillaSearchHandler(deskbar.Handl
 				get_firefox_home_file("searchplugins"),
 				get_firefox_home_file("search"),
 				expanduser("~/.mozilla/searchplugins"),
+				"%%X11BASE%%/lib/firefox/searchplugins",
 				"/usr/lib/firefox/searchplugins",
 				"/usr/local/lib/firefox/searchplugins",
 				"/usr/lib/mozilla-firefox/searchplugins",
@@ -197,6 +198,7 @@ class MozillaSearchHandler(deskbar.Handl
 			smart_dirs = [
 				get_mozilla_home_file("search"),
 				expanduser("~/.mozilla/searchplugins"),
+				"%%X11BASE%%/lib/mozilla/searchplugins",
 				"/usr/lib/mozilla/searchplugins",
 				"/usr/local/lib/mozilla/searchplugins"]
 		
