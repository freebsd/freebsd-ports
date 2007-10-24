--- deskbar/deskbar-applet.py.orig	Tue Jul 10 15:28:29 2007
+++ deskbar/deskbar-applet.py	Tue Jul 10 15:29:43 2007
@@ -43,10 +43,10 @@
     gettext.bind_textdomain_codeset('deskbar-applet','UTF-8')
 gettext.textdomain('deskbar-applet')
 
-locale.bindtextdomain('deskbar-applet', abspath(join(deskbar.defs.DATA_DIR, "locale")))
-if hasattr(locale, 'bind_textdomain_codeset'):
-    locale.bind_textdomain_codeset('deskbar-applet','UTF-8')
-locale.textdomain('deskbar-applet')
+#locale.bindtextdomain('deskbar-applet', abspath(join(deskbar.defs.DATA_DIR, "locale")))
+#if hasattr(locale, 'bind_textdomain_codeset'):
+#    locale.bind_textdomain_codeset('deskbar-applet','UTF-8')
+#locale.textdomain('deskbar-applet')
 
 # Enable threads
 gtk.gdk.threads_init()
