--- hamster/hamster-applet.py.orig	2008-08-07 10:22:46.000000000 -0400
+++ hamster/hamster-applet.py	2008-08-07 10:23:13.000000000 -0400
@@ -51,10 +51,10 @@ if hasattr(gettext, 'bind_textdomain_cod
     gettext.bind_textdomain_codeset('hamster-applet','UTF-8')
 gettext.textdomain('hamster-applet')
 
-locale.bindtextdomain('hamster-applet', abspath(join(hamster.defs.DATA_DIR, "locale")))
-if hasattr(locale, 'bind_textdomain_codeset'):
-    locale.bind_textdomain_codeset('hamster-applet','UTF-8')
-locale.textdomain('hamster-applet')
+#locale.bindtextdomain('hamster-applet', abspath(join(hamster.defs.DATA_DIR, "locale")))
+#if hasattr(locale, 'bind_textdomain_codeset'):
+#    locale.bind_textdomain_codeset('hamster-applet','UTF-8')
+#locale.textdomain('hamster-applet')
 
 hamster.__init_db()
 import hamster.applet
