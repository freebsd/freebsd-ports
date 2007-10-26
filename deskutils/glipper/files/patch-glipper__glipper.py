--- ./glipper/glipper.py.orig	2007-10-23 15:25:36.000000000 +0400
+++ ./glipper/glipper.py	2007-10-23 15:29:08.000000000 +0400
@@ -27,10 +27,10 @@
 	gettext.bind_textdomain_codeset('glipper','UTF-8')
 gettext.textdomain('glipper')
 
-locale.bindtextdomain('glipper', abspath(join(glipper.defs.DATA_DIR, "locale")))
-if hasattr(locale, 'bind_textdomain_codeset'):
-	locale.bind_textdomain_codeset('glipper','UTF-8')
-locale.textdomain('glipper')
+#locale.bindtextdomain('glipper', abspath(join(glipper.defs.DATA_DIR, "locale")))
+#if hasattr(locale, 'bind_textdomain_codeset'):
+#	locale.bind_textdomain_codeset('glipper','UTF-8')
+#locale.textdomain('glipper')
 
 def applet_factory(applet, iid):
 	print 'Starting Glipper instance:', applet, iid
