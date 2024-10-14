--- setup.py.orig	2024-10-08 03:13:44 UTC
+++ setup.py
@@ -43,7 +43,7 @@ setup(
         "packaging",
         "typing-inspect>=0.7.1",
         "typing_extensions>=3.10.0",
-        "z3-solver==4.13.0.0",
+        "z3-solver>=4.13.0.0",
         "importlib_metadata>=4.0.0",
         "pygls>=1.0.0",  # For the LSP server
         "typeshed-client>=2.0.5",
