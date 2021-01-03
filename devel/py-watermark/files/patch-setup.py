--- setup.py.orig	2020-11-24 04:17:25 UTC
+++ setup.py
@@ -23,7 +23,7 @@ setup(
     packages=find_packages(exclude=[]),
     install_requires=[
         "ipython",
-        'importlib-metadata < 3.0 ; python_version < "3.8"',
+        'importlib-metadata; python_version < "3.8"',
     ],
     long_description=dedent(
         """\
