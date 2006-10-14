--- deskbar/__init__.py.orig	Thu Sep  7 15:04:34 2006
+++ deskbar/__init__.py	Thu Sep  7 15:04:50 2006
@@ -26,7 +26,7 @@ if _check(name):
 if UNINSTALLED_DESKBAR:
 	SHARED_DATA_DIR = abspath(join(dirname(__file__), '..', 'data'))
 else:
-	SHARED_DATA_DIR = join(DATA_DIR, "deskbar-applet")
+	SHARED_DATA_DIR = join(DATA_DIR, "gnome", "deskbar-applet")
 print "Data Dir: %s" % SHARED_DATA_DIR
 
 HANDLERS_DIR = []
