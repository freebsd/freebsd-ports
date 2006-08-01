--- data/py/__init__.py	Tue Aug  1 00:19:19 2006
+++ data/py/__init__.py	Tue Aug  1 00:19:52 2006
@@ -33,7 +33,7 @@
 datarootpath = os.path.join(sys.prefix,'share','xgngeo')
 
 #Internationalization.
-gettext.install("xgngeo",os.path.join(datarootpath,"locale"))
+gettext.install("xgngeo",os.path.join(sys.prefix,"share","locale"))
 
 class XGngeo:
 	def __init__(self):
