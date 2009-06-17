--- GTG/__init__.py.orig	2009-04-04 01:00:16.000000000 +0400
+++ GTG/__init__.py	2009-06-17 12:59:18.000000000 +0400
@@ -32,7 +32,7 @@
 EMAIL           = "gtg@lists.launchpad.net"
 VERSION         = '0.1.1'
 LOCAL_ROOTDIR   = os.path.abspath(os.path.join(os.path.dirname(__file__), '..')) 
-DIST_ROOTDIR    = "/usr/share/gtg"
+DIST_ROOTDIR    = "/usr/local/share/gtg"
 
 # CREDITS
 AUTHORS     = ["Main developers:", \
@@ -60,7 +60,7 @@
 GETTEXT_DOMAIN = 'gtg'
 LOCALE_PATH = abspath(join(dirname(__file__), pardir, 'locales'))
 if not os.path.isdir(LOCALE_PATH):
-    LOCALE_PATH = '/usr/share/locale'
+    LOCALE_PATH = '/usr/local/share/locale'
 languages_used = []
 lc, encoding = locale.getdefaultlocale()
 if lc:
