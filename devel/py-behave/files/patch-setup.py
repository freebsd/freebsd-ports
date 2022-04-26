--- setup.py.orig	2018-02-25 16:27:09 UTC
+++ setup.py
@@ -100,8 +100,6 @@ setup(
             "pylint",
         ],
     },
-    # MAYBE-DISABLE: use_2to3
-    use_2to3= bool(python_version >= 3.0),
     license="BSD",
     classifiers=[
         "Development Status :: 4 - Beta",
