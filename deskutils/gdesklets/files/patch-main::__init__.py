--- main/__init__.py.orig	Thu Oct  5 16:14:40 2006
+++ main/__init__.py	Tue Nov 14 13:38:57 2006
@@ -7,7 +7,7 @@
 # gDesklets home paths
 HOME = os.path.abspath(os.path.join(os.path.dirname(__file__), os.pardir))
 USERHOME = os.path.join(os.path.expanduser("~"), ".gdesklets")
-OLDHOME = os.path.join(HOME, os.pardir, os.pardir, "share", "gdesklets")
+OLDHOME = os.path.join(HOME, os.pardir, os.pardir, "share", "gnome", "gdesklets")
 
 # we need the DISPLAY variable
 try:
