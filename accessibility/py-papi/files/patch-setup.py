--- setup.py.orig	2009-03-01 11:06:58 UTC
+++ setup.py
@@ -212,7 +212,7 @@ interface system to enable accessibility for any pytho
         "package_dir" : { "papi" : "lib" },
         "ext_modules" : [papi],
         "headers" : headers,
-        "data_files" : docfiles,
+        "data_files" : [],
         "classifiers" : [
             "Development Status :: 3 - Alpha",
             "Intended Audience :: Developers",
