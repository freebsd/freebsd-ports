-- The in-tree setuptools version does not emit PEP 639 License-Expression;
-- fall back to the classic License field so the test passes with the
-- FreeBSD ports tree's setuptools.

--- tests/test_packaging.py.orig	2026-09-14 14:33:42 UTC
+++ tests/test_packaging.py
@@ -18,7 +18,8 @@ def test_license() -> None:
 
 def test_license() -> None:
     metadata = importlib.metadata.metadata("pybase64")
-    assert metadata["License-Expression"] == "BSD-2-Clause"
+    license_expression = metadata.get("License-Expression")
+    assert license_expression == "BSD-2-Clause" or metadata["License"].startswith("BSD-2-Clause")
 
 
 @pytest.mark.pypi_distribution
