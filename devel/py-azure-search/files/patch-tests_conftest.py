-- Make the test proxy/sanitizer imports from devtools_testutils optional so
-- that the unit test suite can run in the FreeBSD ports environment.  The
-- devtools_testutils package is an internal Azure SDK build/test tool that
-- is not published on PyPI and is therefore unavailable as a port dependency.
-- Live/recorded tests that rely on the proxy are excluded from the port test
-- run via TEST_ARGS; only the offline unit tests are executed.
-- Upstream feature request to publish the test utilities:
-- https://github.com/azure/azure-sdk-for-python/issues/47397

--- tests/conftest.py.orig	2026-09-24 02:57:41 UTC
+++ tests/conftest.py
@@ -5,15 +5,29 @@ import pytest
 # -------------------------------------------------------------------------

 import pytest
-from devtools_testutils import test_proxy, remove_batch_sanitizers
-from devtools_testutils.sanitizers import (
-    add_remove_header_sanitizer,
-    add_general_regex_sanitizer,
-)
+
+try:
+    from devtools_testutils import test_proxy, remove_batch_sanitizers
+    from devtools_testutils.sanitizers import (
+        add_remove_header_sanitizer,
+        add_general_regex_sanitizer,
+    )
+    _HAVE_DEVTOOLS = True
+except ImportError:
+    _HAVE_DEVTOOLS = False

+
+if not _HAVE_DEVTOOLS:
+    @pytest.fixture(scope="session")
+    def test_proxy():
+        return None
+

 @pytest.fixture(scope="session", autouse=True)
 def add_sanitizers(test_proxy):
+    if not _HAVE_DEVTOOLS:
+        return
+
     add_remove_header_sanitizer(headers="api-key")

     # Ensure all search service endpoint names are mocked to "test-service"
