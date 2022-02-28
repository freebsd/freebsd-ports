--- setup.py.orig	2022-01-25 22:10:16 UTC
+++ setup.py
@@ -503,12 +503,6 @@ def setup_requires():
         req = parse_requirements("requirements_dev.txt")
         req = list(filter(lambda r: not r.startswith("-r"), req))
 
-    req_cmake = list(filter(lambda r: "cmake" in r, req))[0]
-
-    # Add cmake requirement if libtiledb is not found and cmake is not available.
-    if not libtiledb_exists(LIB_DIRS) and not cmake_available():
-        req.append(req_cmake)
-
     return req
 
 
