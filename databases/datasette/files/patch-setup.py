--- setup.py.orig	2025-03-16 20:50:09 UTC
+++ setup.py
@@ -70,7 +70,7 @@ setup(
         [console_scripts]
         datasette=datasette.cli:cli
     """,
-    setup_requires=["pytest-runner"],
+    setup_requires=[],
     extras_require={
         "docs": [
             "furo==2024.8.6",
