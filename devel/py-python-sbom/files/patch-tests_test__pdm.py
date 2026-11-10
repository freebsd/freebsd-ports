-- Use the PEP 621 license table form and drop license-files from the
-- [project] table so the test fixture validates with the setuptools
-- version in the FreeBSD devel/py-setuptools port.
--- tests/test_pdm.py.orig	2026-11-10 10:02:09 UTC
+++ tests/test_pdm.py
@@ -36,8 +36,7 @@ description = "an example"
 name = "example"
 version = "1.0"
 description = "an example"
-license = "MIT"
-license-files = ["LICENSE"]
+license = {text = "MIT"}
 urls.Source = "https://github.com/example/example"
 """
     (root / "pyproject.toml").write_text(f"{project}{tables}", encoding="utf-8")
