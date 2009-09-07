--- vboxgtk/__init__.py.orig	2009-06-20 00:16:28.000000000 +1000
+++ vboxgtk/__init__.py	2009-09-04 21:47:01.000000000 +1000
@@ -37,8 +37,6 @@
 gettext_domain = 'vboxgtk'
 gettext.install(gettext_domain, locale_path, unicode = True)
 locale.setlocale(locale.LC_ALL, '')
-locale.bindtextdomain(gettext_domain, locale_path)
-locale.textdomain(gettext_domain)
 
 
 # Import main for the launch script
