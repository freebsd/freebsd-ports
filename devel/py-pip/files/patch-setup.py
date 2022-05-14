--- setup.py.orig	2022-05-11 19:03:44 UTC
+++ setup.py
@@ -75,8 +75,6 @@ setup(
     entry_points={
         "console_scripts": [
             "pip=pip._internal.cli.main:main",
-            "pip{}=pip._internal.cli.main:main".format(sys.version_info[0]),
-            "pip{}.{}=pip._internal.cli.main:main".format(*sys.version_info[:2]),
         ],
     },
     zip_safe=False,
