-- Use the PEP 621 license table form and drop license-files from the
-- [project] table so the test fixture validates with the setuptools
-- version in the FreeBSD devel/py-setuptools port.
--- tests/hatch/conftest.py.orig	2026-11-10 10:02:09 UTC
+++ tests/hatch/conftest.py
@@ -26,8 +26,7 @@ description = "an example"
 name = "Example"
 version = "1.0"
 description = "an example"
-license = "MIT"
-license-files = ["LICENSE"]
+license = {text = "MIT"}
 dependencies = ["packaging>=24"]
 urls.Source = "https://github.com/example/example"
 
