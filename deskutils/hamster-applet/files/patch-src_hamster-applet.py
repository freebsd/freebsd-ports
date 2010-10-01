--- src/hamster-applet.py	2010-06-22 13:59:09.000000000 +0400
+++ src/hamster-applet.py	2010-09-26 01:52:33.000000000 +0400
@@ -96,7 +96,7 @@
 
         # Setup i18n
         locale_dir = os.path.abspath(os.path.join(defs.DATA_DIR, "locale"))
-        for module in (gettext, locale):
+        for module in (gettext,):
             module.bindtextdomain('hamster-applet', locale_dir)
             module.textdomain('hamster-applet')
 
