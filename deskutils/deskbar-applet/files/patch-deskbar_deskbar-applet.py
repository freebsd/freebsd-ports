--- deskbar/deskbar-applet.py.orig	Mon May 29 19:20:47 2006
+++ deskbar/deskbar-applet.py	Mon May 29 19:20:54 2006
@@ -42,10 +42,10 @@ if hasattr(gettext, 'bind_textdomain_cod
 	gettext.bind_textdomain_codeset('deskbar-applet','UTF-8')
 gettext.textdomain('deskbar-applet')
 
-locale.bindtextdomain('deskbar-applet', abspath(join(deskbar.defs.DATA_DIR, "locale")))
-if hasattr(locale, 'bind_textdomain_codeset'):
-	locale.bind_textdomain_codeset('deskbar-applet','UTF-8')
-locale.textdomain('deskbar-applet')
+#locale.bindtextdomain('deskbar-applet', abspath(join(deskbar.defs.DATA_DIR, "locale")))
+#if hasattr(locale, 'bind_textdomain_codeset'):
+#	locale.bind_textdomain_codeset('deskbar-applet','UTF-8')
+#locale.textdomain('deskbar-applet')
 
 import gtkexcepthook
 
