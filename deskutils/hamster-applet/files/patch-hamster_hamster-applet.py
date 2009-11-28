--- hamster/hamster-applet.py.orig	2009-07-19 21:41:20.000000000 +1000
+++ hamster/hamster-applet.py	2009-07-19 21:41:46.000000000 +1000
@@ -37,14 +37,14 @@ from hamster import defs
 from hamster.configuration import runtime
 
 # Setup i18n
-locale_dir = os.path.abspath(os.path.join(defs.DATA_DIR, "locale"))
+#locale_dir = os.path.abspath(os.path.join(defs.DATA_DIR, "locale"))
 
-for module in (gettext, locale):
-    module.bindtextdomain('hamster-applet', locale_dir)
-    module.textdomain('hamster-applet')
+#for module in (gettext, locale):
+#    module.bindtextdomain('hamster-applet', locale_dir)
+#    module.textdomain('hamster-applet')
 
-    if hasattr(module, 'bind_textdomain_codeset'):
-        module.bind_textdomain_codeset('hamster-applet','UTF-8')
+#    if hasattr(module, 'bind_textdomain_codeset'):
+#        module.bind_textdomain_codeset('hamster-applet','UTF-8')
 
 
 from hamster.applet import HamsterApplet
