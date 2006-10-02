--- data/py/__init__.py	Sun Oct  1 20:49:37 2006
+++ data/py/__init__.py	Sun Oct  1 20:50:23 2006
@@ -63,7 +63,7 @@
 datarootpath = os.path.join(sys.prefix, 'share', 'xgngeo')
 
 # Internationalization.
-gettext.install("xgngeo", os.path.join(datarootpath, "locale"))
+gettext.install("xgngeo", os.path.join(sys.prefix,"share", "locale"))
 
 class XGngeo:
 	def __init__(self):
