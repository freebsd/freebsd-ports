Description: Fall back to importlib.util.find_spec().loader where
  pkgutil.get_loader (removed in Python 3.14) is missing.
Issue ID: https://github.com/python-postgres/fe/pull/130
Changeset: none (py-postgresql 1.3.1 still imports pkgutil.get_loader)

--- postgresql/python/command.py.orig	2025-03-15 22:23:57 UTC
+++ postgresql/python/command.py
@@ -57,7 +57,15 @@ import contextlib
 from gettext import gettext as _
 from traceback import print_exception
 
-from pkgutil import get_loader as module_loader
+try:
+	from pkgutil import get_loader as module_loader
+except ImportError:
+	# pkgutil.get_loader was removed in Python 3.14
+	import importlib.util
+
+	def module_loader(name):
+		spec = importlib.util.find_spec(name)
+		return spec.loader if spec is not None else None
 
 class single_loader(object):
 	"""
