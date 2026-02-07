--- setup.py.orig	2024-10-18 20:24:28 UTC
+++ setup.py
@@ -29,7 +29,7 @@ setup(
     install_requires=[
         "dataclasses; python_version<'3.7'",
         "click>=7",
-        "virtualenv<=20.26.6",
+        "virtualenv",
         "rich",
         "pexpect",
         "packaging",
