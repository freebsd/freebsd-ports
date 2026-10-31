--- setup.py.orig	2024-12-11 14:48:27 UTC
+++ setup.py
@@ -2,7 +2,7 @@ from setuptools import setup
 
 from setuptools import setup
 
-VERSION = "0.5"
+VERSION = "0.5.1"
 
 setup(
     name="iniparse",
@@ -38,17 +38,4 @@ use.""",
         "Topic :: Software Development :: Libraries :: Python Modules",
     ],
     packages=["iniparse"],
-    data_files=[
-        (
-            "share/doc/iniparse-%s" % VERSION,
-            [
-                "README.md",
-                "LICENSE-PSF",
-                "LICENSE",
-                "Changelog",
-                "html/index.html",
-                "html/style.css",
-            ],
-        ),
-    ],
 )
