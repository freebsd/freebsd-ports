-- This patch adds tests/conftest.py which is missing from the PyPI source distribution.
-- The file is taken from the GitHub repository at the same version tag.
-- Without this file, the tests cannot be run (the gctorture fixture is missing).
--- /dev/null
+++ tests/conftest.py
@@ -0,0 +1,9 @@
+import pytest
+from rchitect import rcall
+
+
+@pytest.fixture(scope='function')
+def gctorture():
+    rcall("gctorture", True)
+    yield
+    rcall("gctorture", False)
