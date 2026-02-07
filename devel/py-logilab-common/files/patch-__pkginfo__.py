--- __pkginfo__.py.orig	2023-10-17 13:25:55 UTC
+++ __pkginfo__.py
@@ -45,7 +45,7 @@ install_requires = [
     "setuptools",
     "mypy-extensions",
     "typing_extensions",
-    'importlib_metadata>=6,<7; python_version < "3.10"',
+    'importlib_metadata>=6; python_version < "3.10"',
 ]
 tests_require = [
     "pytz",
