Avoid loading of "requirements.bzl" because it requires "pip_import" which
is already disabled in "defs.bzl".

--- pylib/orjson.bzl.orig	2021-05-04 05:04:50 UTC
+++ pylib/orjson.bzl
@@ -1,8 +1,7 @@
-load("@py_deps//:requirements.bzl", "requirement")
 
 def orjson_if_available():
     "Include orjson if it's listed in requirements.txt."
-    target = requirement("orjson")
+    target = "not_found"
     if "not_found" in target:
         return []
     else:
