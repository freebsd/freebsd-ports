--- GTG/__init__.py.orig	2009-04-04 01:00:16.000000000 +0400
+++ GTG/__init__.py	2009-06-17 12:59:18.000000000 +0400
@@ -60,7 +60,7 @@
 GETTEXT_DOMAIN = 'gtg'
 LOCALE_PATH = abspath(join(dirname(__file__), pardir, 'locales'))
 if not os.path.isdir(LOCALE_PATH):
-    LOCALE_PATH = '/usr/share/locale'
+    LOCALE_PATH = '/usr/local/share/locale'
 languages_used = []
 lc, encoding = locale.getdefaultlocale()
 if lc:
