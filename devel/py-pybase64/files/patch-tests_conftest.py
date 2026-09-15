--- tests/conftest.py.orig	2026-09-14 14:33:46 UTC
+++ tests/conftest.py
@@ -0,0 +1,23 @@
+from __future__ import annotations
+
+import pytest
+
+from . import utils
+
+simd = utils.simd
+
+
+@pytest.fixture(autouse=True)
+def _autoskip_benchmark(request: pytest.FixtureRequest) -> None:
+    marker = request.node.get_closest_marker("benchmark")
+    running = request.config.getoption("--codspeed", default=False)
+    if marker is not None and not running:
+        pytest.skip("needs '--codspeed' to run")
+
+
+@pytest.fixture(autouse=True)
+def _autoskip_pypi_distribution(request: pytest.FixtureRequest) -> None:
+    marker = request.node.get_closest_marker("pypi_distribution")
+    running = request.config.getoption("--pypi-distribution", default=False)
+    if marker is not None and not running:
+        pytest.skip("needs '--pypi-distribution' to run")
