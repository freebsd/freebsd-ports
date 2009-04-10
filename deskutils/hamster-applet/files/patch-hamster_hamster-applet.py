--- hamster/hamster-applet.py.orig	2009-02-13 16:02:00.000000000 -0500
+++ hamster/hamster-applet.py	2009-02-27 19:50:13.000000000 -0500
@@ -52,10 +52,10 @@ if hasattr(gettext, 'bind_textdomain_cod
     gettext.bind_textdomain_codeset('hamster-applet','UTF-8')
 gettext.textdomain('hamster-applet')
 
-locale.bindtextdomain('hamster-applet', locale_dir)
-if hasattr(locale, 'bind_textdomain_codeset'):
-    locale.bind_textdomain_codeset('hamster-applet','UTF-8')
-locale.textdomain('hamster-applet')
+#locale.bindtextdomain('hamster-applet', locale_dir)
+#if hasattr(locale, 'bind_textdomain_codeset'):
+#    locale.bind_textdomain_codeset('hamster-applet','UTF-8')
+#locale.textdomain('hamster-applet')
 
 hamster.__init_db()
 import hamster.applet
