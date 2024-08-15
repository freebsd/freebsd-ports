--- setup.py.orig	2024-05-10 03:17:53 UTC
+++ setup.py
@@ -44,7 +44,7 @@ setup(
     ],
     extras_require={
         "keyring": ["keyring >= 12.2.0"],
-        "sshtunnel": ["sshtunnel >= 0.4.0"],
+        "sshtunnel": ["sshtunnel"],
     },
     python_requires=">=3.8",
     entry_points="""
