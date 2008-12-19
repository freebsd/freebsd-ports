
$FreeBSD$

--- src/labyrinth.py.orig
+++ src/labyrinth.py
@@ -56,11 +56,12 @@
 if hasattr(gettext, 'bind_textdomain_codeset'):
 	gettext.bind_textdomain_codeset('labyrinth','UTF-8')
 gettext.textdomain('labyrinth')
-if not os.name == 'nt':
-	locale.bindtextdomain('labyrinth', localedir)
-	if hasattr(locale, 'bind_textdomain_codeset'):
-		locale.bind_textdomain_codeset('labyrinth','UTF-8')
-	locale.textdomain('labyrinth')
+if hasattr(locale, 'bindtextdomain'):
+	if not os.name == 'nt':
+		locale.bindtextdomain('labyrinth', localedir)
+		if hasattr(locale, 'bind_textdomain_codeset'):
+			locale.bind_textdomain_codeset('labyrinth','UTF-8')
+		locale.textdomain('labyrinth')
 
 gtk.glade.bindtextdomain('labyrinth')
 gtk.glade.textdomain('labyrinth')
