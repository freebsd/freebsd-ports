--- main/__init__.py.orig	Mon Feb 28 12:11:37 2005
+++ main/__init__.py	Mon Feb 28 12:12:18 2005
@@ -20,7 +20,7 @@
     USERHOME = os.path.join(os.environ["APPDATA"], "gDesklets")
 else:
     USERHOME = os.path.join(os.path.expanduser("~"), ".gdesklets")
-OLDHOME = os.path.join(HOME, os.pardir, os.pardir, "share", "gdesklets")
+OLDHOME = os.path.join(HOME, os.pardir, os.pardir, "share", "gnome", "gdesklets")
 
 
 # we need the DISPLAY variable
