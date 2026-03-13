--- setup.py.orig	2017-11-19 23:15:25 UTC
+++ setup.py
@@ -54,12 +54,4 @@ if "0.1.5".startswith("%%"):
     sys.exit(errlvl)
 
 
-##
-## Normal d2to1 setup
-##
-
-setup(
-    setup_requires=['d2to1'],
-    extras_require={'test': ['nose', ]},
-    d2to1=True
-)
+setup(extras_require={'test': ['nose', ]})
