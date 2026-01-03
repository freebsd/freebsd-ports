--- hgdemandimport/__init__.py.orig	2025-04-03 13:32:42 UTC
+++ hgdemandimport/__init__.py
@@ -60,6 +60,7 @@ IGNORES = {
     'setuptools',
     '_distutils_hack.override',
     # threading is locally imported by importlib.util.LazyLoader.exec_module
+    '_contextvars',
     '_weakrefset',
     'warnings',
     'threading',
