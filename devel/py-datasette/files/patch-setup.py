--- setup.py.orig	2023-03-08 20:52:55 UTC
+++ setup.py
@@ -62,7 +62,6 @@ setup(
         [console_scripts]
         datasette=datasette.cli:cli
     """,
-    setup_requires=["pytest-runner"],
     extras_require={
         "docs": [
             "furo==2022.9.29",
