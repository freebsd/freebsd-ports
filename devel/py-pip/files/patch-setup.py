--- setup.py.orig	2015-06-19 02:39:23 UTC
+++ setup.py
@@ -98,8 +98,6 @@ setup(
     entry_points={
         "console_scripts": [
             "pip=pip:main",
-            "pip%s=pip:main" % sys.version[:1],
-            "pip%s=pip:main" % sys.version[:3],
         ],
     },
     tests_require=tests_require,
