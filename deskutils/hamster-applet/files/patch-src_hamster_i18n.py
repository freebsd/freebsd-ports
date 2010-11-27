--- src/hamster/i18n.py.orig	2010-11-16 15:17:44.000000000 +0100
+++ src/hamster/i18n.py	2010-11-16 15:18:14.000000000 +0100
@@ -19,7 +19,7 @@
     if defs:
         locale_dir = os.path.realpath(os.path.join(defs.DATA_DIR, "locale"))
 
-        for module in (locale,gettext):
+        for module in (gettext,):
             module.bindtextdomain('hamster-applet', locale_dir)
             module.textdomain('hamster-applet')
 
