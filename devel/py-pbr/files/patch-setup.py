--- ./setup.py.orig	2013-06-18 20:01:04.819952450 +1000
+++ ./setup.py	2013-06-18 20:01:17.687327396 +1000
@@ -18,4 +18,5 @@
 
 setuptools.setup(
     setup_requires=['d2to1>=0.2.10,<0.3'],
+    zip_safe=False,
     d2to1=True)
