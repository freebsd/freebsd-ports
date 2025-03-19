--- setup.py.orig	2025-03-12 03:57:29 UTC
+++ setup.py
@@ -20,7 +20,7 @@ setup(
     python_requires=">=3.9",
     install_requires=[
         "prettytable<4",
-        "sqlglot>=24.0.0,<26.10",
+        "sqlglot>=24.0.0",
         "typing_extensions",
     ],
     extras_require={
