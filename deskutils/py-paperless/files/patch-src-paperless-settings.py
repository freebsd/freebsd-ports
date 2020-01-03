--- src/paperless/settings.py.orig	2019-01-27 13:48:05 UTC
+++ src/paperless/settings.py
@@ -10,7 +10,9 @@ For the full list of settings and their 
 https://docs.djangoproject.com/en/1.10/ref/settings/
 """
 
+import json
 import os
+import re
 
 from dotenv import load_dotenv
 
@@ -102,7 +104,7 @@ MIDDLEWARE = [
 ]
 
 # We allow CORS from localhost:8080
-CORS_ORIGIN_WHITELIST = tuple(os.getenv("PAPERLESS_CORS_ALLOWED_HOSTS", "localhost:8080").split(","))
+CORS_ORIGIN_WHITELIST = tuple(os.getenv("PAPERLESS_CORS_ALLOWED_HOSTS", "http://localhost:8080").split(","))
 
 # If auth is disabled, we just use our "bypass" authentication middleware
 if bool(os.getenv("PAPERLESS_DISABLE_LOGIN", "false").lower() in ("yes", "y", "1", "t", "true")):
@@ -314,6 +316,15 @@ FY_END = os.getenv("PAPERLESS_FINANCIAL_
 DATE_ORDER = os.getenv("PAPERLESS_DATE_ORDER", "DMY")
 FILENAME_DATE_ORDER = os.getenv("PAPERLESS_FILENAME_DATE_ORDER")
 
+# Transformations applied before filename parsing
+FILENAME_PARSE_TRANSFORMS = []
+_filename_parse_transforms = os.getenv("PAPERLESS_FILENAME_PARSE_TRANSFORMS")
+if _filename_parse_transforms:
+    FILENAME_PARSE_TRANSFORMS = [(
+            re.compile(t["pattern"]), t["repl"])
+        for t in json.loads(_filename_parse_transforms)
+    ]
+
 # Specify for how many years a correspondent is considered recent. Recent
 # correspondents will be shown in a separate "Recent correspondents" filter as
 # well. Set to 0 to disable this filter.
