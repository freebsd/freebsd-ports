--- deskbar/deskbar-applet.py.orig	Sat Nov 19 14:15:58 2005
+++ deskbar/deskbar-applet.py	Thu Dec  8 22:23:00 2005
@@ -34,8 +34,8 @@
 gettext.bindtextdomain('deskbar-applet', abspath(join(deskbar.defs.DATA_DIR, "locale")))
 gettext.textdomain('deskbar-applet')
 
-locale.bindtextdomain('deskbar-applet', abspath(join(deskbar.defs.DATA_DIR, "locale")))
-locale.textdomain('deskbar-applet')
+#locale.bindtextdomain('deskbar-applet', abspath(join(deskbar.defs.DATA_DIR, "locale")))
+#locale.textdomain('deskbar-applet')
 
 def applet_factory(applet, iid):
 	print 'Starting Deskbar instance:', applet, iid
