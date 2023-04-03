--- stevedore/tests/test_extension.py.orig	2023-02-10 18:29:38 UTC
+++ stevedore/tests/test_extension.py
@@ -13,9 +13,17 @@
 """Tests for stevedore.extension
 """
 
-import importlib.metadata as importlib_metadata
 import operator
 from unittest import mock
+
+# only until 2023-06-23 when lang/python37 expires
+# https://opendev.org/openstack/stevedore/commit/ccd17543a37143913e886f9306be10d40260fdf3
+try:
+    # For python 3.8 and later
+    import importlib.metadata as importlib_metadata
+except ImportError:
+    # For everyone else
+    import importlib_metadata
 
 from stevedore import exception
 from stevedore import extension
