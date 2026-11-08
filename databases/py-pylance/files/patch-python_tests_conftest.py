-- Make the pytest-xdist controller hook conditional so the test suite can
-- be collected when pytest-xdist is installed but not loaded.
-- The FreeBSD port uses --disable-plugin-autoload, which keeps pytest-xdist
-- from registering its hook specifications; without this guard the
-- unconditional pytest_configure_node definition causes a plugin validation
-- internal error during collection.

--- python/tests/conftest.py.orig	2026-09-06 05:04:50 UTC
+++ python/tests/conftest.py
@@ -108,8 +108,15 @@ def pytest_configure(config):

         use_version_snapshot(workerinput["lance_compat_versions"])

+    # Only register the xdist controller hook when pytest-xdist is actually
+    # loaded. With --disable-plugin-autoload (used by the FreeBSD port test run)
+    # pytest-xdist is installed but not loaded, so an unconditional top-level
+    # hook definition causes an internal error during collection.
+    if config.pluginmanager.hasplugin("xdist"):
+        config.pluginmanager.register(_LanceXdistCompatPlugin(), "lance_xdist_compat")

-def pytest_configure_node(node):
+
+class _LanceXdistCompatPlugin:
     """Resolve the compat version list once, on the xdist controller.

     The compat tests are parametrized over the pylance releases published to
@@ -119,9 +126,11 @@ def pytest_configure_node(node):
     mid-run gives one worker a different parameter set, and xdist aborts the
     whole run with "Different tests were collected".
     """
-    from compat.compat_decorator import version_snapshot

-    node.workerinput["lance_compat_versions"] = version_snapshot()
+    def pytest_configure_node(self, node):
+        from compat.compat_decorator import version_snapshot
+
+        node.workerinput["lance_compat_versions"] = version_snapshot()


 # tryfirst because xdist reads xdist_group off each item to build its scheduling
