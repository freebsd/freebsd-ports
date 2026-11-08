-- Fix tests for Python 3.12 where test.support attributes were moved to sub-modules.
-- test.support.TESTFN, rmtree, can_symlink, skip_unless_symlink, EnvironmentVarGuard
-- were moved to test.support.os_helper; import_module moved to test.support.import_helper.
--- tests/test_pathlib2.py.orig	2026-09-10 09:22:20 UTC
+++ tests/test_pathlib2.py
@@ -46,6 +46,27 @@ except ImportError:
 except ImportError:
     from test import test_support as support  # type: ignore
 
+# Python 3.12 compatibility: many test.support attributes were moved to sub-modules
+try:
+    from test.support import os_helper as _os_helper
+    from test.support import import_helper as _import_helper
+    for _attr, _src in [
+        ("TESTFN", None),
+        ("rmtree", _os_helper),
+        ("can_symlink", _os_helper),
+        ("skip_unless_symlink", _os_helper),
+        ("EnvironmentVarGuard", _os_helper),
+        ("import_module", _import_helper),
+    ]:
+        if not hasattr(support, _attr):
+            if _src is None:
+                setattr(support, _attr, "test_pathlib2_tmp")
+            else:
+                setattr(support, _attr, getattr(_src, _attr))
+except ImportError:
+    if not hasattr(support, "TESTFN"):
+        support.TESTFN = "test_pathlib2_tmp"
+
 android_not_root = getattr(support, "android_not_root", False)
 
 fs_ascii_encoding_only = six.unichr(0x0100).encode(
