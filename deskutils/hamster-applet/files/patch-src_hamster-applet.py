--- src/hamster-applet.py.orig	2010-01-29 17:37:34.000000000 +0800
+++ src/hamster-applet.py	2010-01-29 17:38:21.000000000 +0800
@@ -95,13 +95,13 @@ if __name__ == "__main__":
         from hamster.configuration import runtime, dialogs
 
         # Setup i18n
-        locale_dir = os.path.abspath(os.path.join(defs.DATA_DIR, "locale"))
-        for module in (gettext, locale):
-            module.bindtextdomain('hamster-applet', locale_dir)
-            module.textdomain('hamster-applet')
+#        locale_dir = os.path.abspath(os.path.join(defs.DATA_DIR, "locale"))
+#        for module in (gettext, locale):
+#            module.bindtextdomain('hamster-applet', locale_dir)
+#            module.textdomain('hamster-applet')
 
-            if hasattr(module, 'bind_textdomain_codeset'):
-                module.bind_textdomain_codeset('hamster-applet','UTF-8')
+#            if hasattr(module, 'bind_textdomain_codeset'):
+#                module.bind_textdomain_codeset('hamster-applet','UTF-8')
 
         gtk.window_set_default_icon_name("hamster-applet")
 
