--- spyder_kernels/customize/tests/test_utils.py.orig	2020-03-04 22:59:51 UTC
+++ spyder_kernels/customize/tests/test_utils.py
@@ -16,7 +16,7 @@ def test_user_sitepackages_in_pathlist():
     """Test that we include user site-packages in pathlist."""
     if sys.platform.startswith('linux'):
         user_path = 'local'
-    elif sys.platform == 'darwin':
+    elif (sys.platform.startswith('darwin') | sys.platform.startswith('freebsd')):
         user_path = os.path.expanduser('~/.local')
     else:
         user_path = 'Roaming'
