--- main/__init__.py.orig	Sun Jan 30 22:40:29 2005
+++ main/__init__.py	Sun Jan 30 22:40:54 2005
@@ -4,7 +4,7 @@
 # gDesklets home paths
 HOME = os.path.abspath(os.path.join(os.path.dirname(__file__), os.pardir))
 USERHOME = os.path.join(os.path.expanduser("~"), ".gdesklets")
-OLDHOME = os.path.join(HOME, os.pardir, os.pardir, "share", "gdesklets")
+OLDHOME = os.path.join(HOME, os.pardir, os.pardir, "share", "gnome", "gdesklets")
 
 # we need the DISPLAY variable
 try:
