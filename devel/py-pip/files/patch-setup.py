--- setup.py.orig	2020-08-11 11:26:41 UTC
+++ setup.py
@@ -76,10 +76,10 @@ setup(
     entry_points={
         "console_scripts": [
             "pip=pip._internal.cli.main:main",
-            "pip{}=pip._internal.cli.main:main".format(sys.version_info[0]),
-            "pip{}.{}=pip._internal.cli.main:main".format(
-                *sys.version_info[:2]
-            ),
+            #"pip{}=pip._internal.cli.main:main".format(sys.version_info[0]),
+            #"pip{}.{}=pip._internal.cli.main:main".format(
+            #    *sys.version_info[:2]
+            #),
         ],
     },
 
