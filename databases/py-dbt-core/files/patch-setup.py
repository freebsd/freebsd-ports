--- setup.py.orig	2024-03-28 03:30:09 UTC
+++ setup.py
@@ -66,9 +66,9 @@ setup(
         # and check compatibility / bump in each new minor version of dbt-core.
         "colorama>=0.3.9,<0.5",
         "pathspec>=0.9,<0.12",
-        "isodate>=0.6,<0.7",
+        "isodate>=0.6",
         # ----
-        "sqlparse>=0.2.3,<0.5",
+        "sqlparse>=0.2.3,<0.6",
         # ----
         # These are major-version-0 packages also maintained by dbt-labs. Accept patches.
         "dbt-extractor~=0.5.0",
@@ -85,7 +85,6 @@ setup(
         "typing-extensions>=3.7.4",
         # ----
         # Match snowflake-connector-python, to ensure compatibility in dbt-snowflake
-        "cffi>=1.9,<2.0.0",
         "idna>=2.5,<4",
         "requests<3.0.0",
         "urllib3~=1.0",
