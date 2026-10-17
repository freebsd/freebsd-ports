Description: Exclude tests from find_packages(), so no top-level 'tests'
  package is installed.
Issue ID: none (upstream inactive; last code commit 80b8276, 2014-10-25)
Changeset: none
TODO: Upstream is inactive; keep locally.

--- setup.py.orig	2014-10-25 20:19:07 UTC
+++ setup.py
@@ -17,7 +17,7 @@ setup(
     platforms=["any"],
     license="BSD",
     url = "http://github.com/ewencp/pyhashxx",
-    packages = find_packages(),
+    packages = find_packages(exclude=["tests", "tests.*"]),
     ext_modules = [ pyhashxx ],
     test_suite = "tests",
     headers = headers,
