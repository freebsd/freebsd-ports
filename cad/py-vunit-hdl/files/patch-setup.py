-- Exclude tests from installation.

--- setup.py.orig	2026-06-11 07:14:15 UTC
+++ setup.py
@@ -42,10 +42,6 @@ DATA_FILES = [os.path.relpath(file_name, "vunit") for 
 setup(
     name="vunit_hdl",
     version=version(),
     packages=[
-        "tests",
-        "tests.lint",
-        "tests.unit",
-        "tests.acceptance",
         "vunit",
         "vunit.com",
         "vunit.parsing",
