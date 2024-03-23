--- setup.py.orig	2015-11-02 21:50:21 UTC
+++ setup.py
@@ -45,7 +45,7 @@ setup(
 print(("%s version %s" % (PkgName, Version.__version__)))
 
 setup(
-    name = PkgName,
+    name = PkgName.lower(),
     version = Version.__version__,
     description = "Collection of utilities including general algorithms, astronomical transformations and Tkinter widgets",
     long_description = long_description,
