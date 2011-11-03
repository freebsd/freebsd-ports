--- ontv/dialogs.py.orig	2010-07-27 03:20:48.000000000 +0400
+++ ontv/dialogs.py	2011-08-19 15:37:50.000000000 +0400
@@ -34,8 +34,8 @@
 from ontv import NAME, VERSION, LOCALE_DIR
 
 import locale
-locale.setlocale(locale.LC_ALL, '')
-locale.bindtextdomain(NAME.lower(), LOCALE_DIR)
+#locale.setlocale(locale.LC_ALL, '')
+#locale.bindtextdomain(NAME.lower(), LOCALE_DIR)
 import gettext
 gettext.bindtextdomain(NAME.lower(), LOCALE_DIR)
 gettext.textdomain(NAME.lower())
