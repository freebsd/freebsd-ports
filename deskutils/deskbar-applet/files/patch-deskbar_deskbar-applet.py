--- deskbar/deskbar-applet.py.orig	Mon Mar 13 23:23:20 2006
+++ deskbar/deskbar-applet.py	Mon Mar 13 23:23:52 2006
@@ -42,10 +42,10 @@
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
 
