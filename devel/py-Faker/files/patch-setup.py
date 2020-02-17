# == (pinned) dependencies are extremely brittle
# for FreeBSD ports. Get upstream to fix (>=) these

--- setup.py.orig	2020-02-17 09:58:01 UTC
+++ setup.py
@@ -63,7 +63,7 @@ setup(
     install_requires=[
         "python-dateutil>=2.4",
         "six>=1.10",
-        "text-unidecode==1.2",
+        "text-unidecode>=1.2",
     ],
     tests_require=[
         "email_validator>=1.0.0,<1.1.0",
