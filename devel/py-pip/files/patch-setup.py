--- setup.py.orig	2022-03-06 23:51:55 UTC
+++ setup.py
@@ -74,9 +74,9 @@ setup(
     },
     entry_points={
         "console_scripts": [
-            "pip=pip._internal.cli.main:main",
-            "pip{}=pip._internal.cli.main:main".format(sys.version_info[0]),
-            "pip{}.{}=pip._internal.cli.main:main".format(*sys.version_info[:2]),
+            # "pip=pip._internal.cli.main:main",
+            # "pip{}=pip._internal.cli.main:main".format(sys.version_info[0]),
+            # "pip{}.{}=pip._internal.cli.main:main".format(*sys.version_info[:2]),
         ],
     },
     zip_safe=False,
