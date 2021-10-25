--- setup.py.orig	2021-03-26 14:25:19 UTC
+++ setup.py
@@ -20,7 +20,7 @@ setup(
     packages=('gitdb', 'gitdb.db', 'gitdb.utils', 'gitdb.test'),
     license="BSD License",
     zip_safe=False,
-    install_requires=['smmap>=3.0.1,<5'],
+    install_requires=['smmap>=3.0.1,<6'],
     long_description="""GitDB is a pure-Python git object database""",
     python_requires='>=3.4',
     # See https://pypi.python.org/pypi?%3Aaction=list_classifiers
