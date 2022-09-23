Since Bazel 4.2.0 bootstrapping Python stub scripts are prepended with
a "Shebang" expression.

--- python/python.bzl.orig	2022-07-10 21:03:57 UTC
+++ python/python.bzl
@@ -77,6 +77,7 @@ py_runtime(
     name = "python_runtime",
     interpreter_path = "{path}",
     python_version = "PY3",
+    stub_shebang = "#!{path}",
     visibility = ["//visibility:public"],
 )
 
