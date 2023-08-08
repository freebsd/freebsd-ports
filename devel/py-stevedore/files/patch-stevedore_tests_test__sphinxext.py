--- stevedore/tests/test_sphinxext.py.orig	2023-02-10 18:29:38 UTC
+++ stevedore/tests/test_sphinxext.py
@@ -12,7 +12,14 @@
 """Tests for the sphinx extension
 """
 
-import importlib.metadata as importlib_metadata
+# only until 2023-06-23 when lang/python37 expires
+# https://opendev.org/openstack/stevedore/commit/ccd17543a37143913e886f9306be10d40260fdf3
+try:
+    # For python 3.8 and later
+    import importlib.metadata as importlib_metadata
+except ImportError:
+    # For everyone else
+    import importlib_metadata
 
 from stevedore import extension
 from stevedore import sphinxext
