--- setup.py.orig	2015-11-14 14:08:36 UTC
+++ setup.py
@@ -78,8 +78,6 @@ setup(
     entry_points={
         "console_scripts": [
             "pip=pip:main",
-            "pip%s=pip:main" % sys.version[:1],
-            "pip%s=pip:main" % sys.version[:3],
         ],
     },
     tests_require=tests_require,
